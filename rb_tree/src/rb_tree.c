// Implementing Red-Black Tree in C (left/right refactor; main unchanged)

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum nodeColor { RED, BLACK };

struct rbNode {
    int data;
    int color;            // enum nodeColor
    struct rbNode* left;  // was link[0]
    struct rbNode* right; // was link[1]
};

struct rbNode* root = NULL;

/* ------------------------------------------------------------
 * Helpers / constants
 * ------------------------------------------------------------ */

// We simulate recursion using explicit stacks during insert/delete.
// Height of RB tree is O(log N); 128 is a generous bound.
#define RB_STACK_MAX 128

// Direction constants (keep 0/1 semantics for existing code)
#define DIR_LEFT 0
#define DIR_RIGHT 1

// Read child pointer by direction
static inline struct rbNode* child(struct rbNode* n, int dir) {
    return dir ? n->right : n->left;
}

// Set child pointer by direction
static inline void set_child(struct rbNode* n, int dir, struct rbNode* c) {
    if (dir)
        n->right = c;
    else
        n->left = c;
}

/* ------------------------------------------------------------
 * Node creation
 * ------------------------------------------------------------ */

static struct rbNode* createNode(int data) {
    struct rbNode* node = (struct rbNode*) malloc(sizeof(struct rbNode));
    node->data = data;
    node->color = RED; // new nodes start red
    node->left = node->right = NULL;
    return node;
}

/* ------------------------------------------------------------
 * Insertion (top-down rebalancing with explicit path stack)
 * ------------------------------------------------------------ */

void insertion(int data) {
    struct rbNode* path_stack[RB_STACK_MAX];
    int dir_stack[RB_STACK_MAX];
    int depth = 0;

    struct rbNode *cur, *rot_x, *rot_y;

    if (!root) {
        root = createNode(data);
        root->color = BLACK;
        return;
    }

    // Descend to insertion leaf position
    cur = root;
    path_stack[depth] = root;
    dir_stack[depth++] = DIR_LEFT;

    int last_dir = DIR_LEFT;
    while (cur != NULL) {
        last_dir = (data - cur->data) >= 0 ? DIR_RIGHT : DIR_LEFT;
        path_stack[depth] = cur;
        dir_stack[depth++] = last_dir;
        cur = child(cur, last_dir);
    }

    // Attach new node
    rot_y = createNode(data);
    set_child(path_stack[depth - 1], last_dir, rot_y);

    // Fix-up: while parent is red
    while (depth >= 3 && path_stack[depth - 1]->color == RED) {
        if (dir_stack[depth - 2] == DIR_LEFT) {
            // parent is left child of grandparent
            rot_y = path_stack[depth - 2]->right; // uncle (right)
            if (rot_y && rot_y->color == RED) {
                // Recolor
                path_stack[depth - 2]->color = RED;
                path_stack[depth - 1]->color = BLACK;
                rot_y->color = BLACK;
                depth -= 2;
            } else {
                if (dir_stack[depth - 1] == DIR_LEFT) {
                    // Left-Left
                    rot_y = path_stack[depth - 1];
                } else {
                    // Left-Right
                    rot_x = path_stack[depth - 1];
                    rot_y = rot_x->right;
                    rot_x->right = rot_y->left;
                    rot_y->left = rot_x;
                    path_stack[depth - 2]->left = rot_y;
                }
                rot_x = path_stack[depth - 2];
                rot_x->color = RED;
                rot_y->color = BLACK;
                rot_x->left = rot_y->right;
                rot_y->right = rot_x;

                if (rot_x == root) {
                    root = rot_y;
                } else {
                    set_child(path_stack[depth - 3], dir_stack[depth - 3], rot_y);
                }
                break;
            }
        } else {
            // parent is right child of grandparent
            rot_y = path_stack[depth - 2]->left; // uncle (left)
            if (rot_y && rot_y->color == RED) {
                // Recolor
                path_stack[depth - 2]->color = RED;
                path_stack[depth - 1]->color = BLACK;
                rot_y->color = BLACK;
                depth -= 2;
            } else {
                if (dir_stack[depth - 1] == DIR_RIGHT) {
                    // Right-Right
                    rot_y = path_stack[depth - 1];
                } else {
                    // Right-Left
                    rot_x = path_stack[depth - 1];
                    rot_y = rot_x->left;
                    rot_x->left = rot_y->right;
                    rot_y->right = rot_x;
                    path_stack[depth - 2]->right = rot_y;
                }
                rot_x = path_stack[depth - 2];
                rot_y->color = BLACK;
                rot_x->color = RED;
                rot_x->right = rot_y->left;
                rot_y->left = rot_x;

                if (rot_x == root) {
                    root = rot_y;
                } else {
                    set_child(path_stack[depth - 3], dir_stack[depth - 3], rot_y);
                }
                break;
            }
        }
    }

    root->color = BLACK;
}

/* ------------------------------------------------------------
 * Deletion (top-down with explicit stacks)
 * ------------------------------------------------------------ */

void deletion(int data) {
    struct rbNode* path_stack[RB_STACK_MAX];
    int dir_stack[RB_STACK_MAX];
    int depth = 0;

    struct rbNode* cur = root;
    struct rbNode* replace = NULL;
    struct rbNode* tmp = NULL;
    struct rbNode* parent = NULL;
    struct rbNode* sibling = NULL;
    struct rbNode* nephew = NULL;

    enum nodeColor color_swap;

    if (!root)
        return;

    // Find node
    while (cur) {
        int go_right = (data - cur->data) >= 0 ? DIR_RIGHT : DIR_LEFT;
        if (data == cur->data)
            break;
        path_stack[depth] = cur;
        dir_stack[depth++] = go_right;
        cur = child(cur, go_right);
    }

    if (!cur)
        return; // not found

    // Splice/remove
    if (cur->right == NULL) {
        // No right child
        if (cur == root && cur->left == NULL) {
            free(cur);
            root = NULL;
            return;
        } else if (cur == root) {
            root = cur->left;
            // color info not needed beyond structure change here
            free(cur);
            cur = NULL;
        } else {
            set_child(path_stack[depth - 1], dir_stack[depth - 1], cur->left);
        }
    } else {
        // Has right subtree
        replace = cur->right;
        if (replace->left == NULL) {
            // Promote right child
            replace->left = cur->left;

            color_swap = (enum nodeColor) replace->color;
            replace->color = cur->color;
            cur->color = color_swap;

            if (cur == root) {
                root = replace;
            } else {
                set_child(path_stack[depth - 1], dir_stack[depth - 1], replace);
            }

            dir_stack[depth] = DIR_RIGHT;
            path_stack[depth++] = replace;
        } else {
            // Find inorder successor
            int anchor = depth++;
            for (;;) {
                dir_stack[depth] = DIR_LEFT;
                path_stack[depth++] = replace;
                tmp = replace->left;
                if (!tmp->left)
                    break;
                replace = tmp;
            }

            dir_stack[anchor] = DIR_RIGHT;
            path_stack[anchor] = tmp;

            if (anchor > 0) {
                set_child(path_stack[anchor - 1], dir_stack[anchor - 1], tmp);
            }

            // Relink children
            tmp->left = cur->left;
            replace->left = tmp->right;
            tmp->right = cur->right;

            if (cur == root) {
                root = tmp;
            }

            color_swap = (enum nodeColor) tmp->color;
            tmp->color = cur->color;
            cur->color = color_swap;
        }
    }

    // Rebalance if removed black (double-black scenarios)
    if (depth < 1)
        return;

    if (cur == NULL || cur->color == BLACK) {
        for (;;) {
            parent = child(path_stack[depth - 1], dir_stack[depth - 1]);
            if (parent && parent->color == RED) {
                parent->color = BLACK;
                break;
            }

            if (depth < 2)
                break;

            if (dir_stack[depth - 2] == DIR_LEFT) {
                // parent is left child
                sibling = path_stack[depth - 1]->right;
                if (!sibling)
                    break;

                if (sibling->color == RED) {
                    path_stack[depth - 1]->color = RED;
                    sibling->color = BLACK;
                    path_stack[depth - 1]->right = sibling->left;
                    sibling->left = path_stack[depth - 1];

                    if (path_stack[depth - 1] == root) {
                        root = sibling;
                    } else {
                        set_child(path_stack[depth - 2], dir_stack[depth - 2], sibling);
                    }

                    dir_stack[depth] = DIR_LEFT;
                    path_stack[depth] = path_stack[depth - 1];
                    path_stack[depth - 1] = sibling;
                    depth++;

                    sibling = path_stack[depth - 1]->right;
                }
                if (!sibling)
                    break;

                if ((!sibling->left || sibling->left->color == BLACK) &&
                    (!sibling->right || sibling->right->color == BLACK)) {
                    sibling->color = RED;
                } else {
                    if (!sibling->right || sibling->right->color == BLACK) {
                        nephew = sibling->left;
                        sibling->color = RED;
                        nephew->color = BLACK;
                        sibling->left = nephew->right;
                        nephew->right = sibling;
                        sibling = path_stack[depth - 1]->right = nephew;
                    }

                    sibling->color = path_stack[depth - 1]->color;
                    path_stack[depth - 1]->color = BLACK;
                    sibling->right->color = BLACK;
                    path_stack[depth - 1]->right = sibling->left;
                    sibling->left = path_stack[depth - 1];

                    if (path_stack[depth - 1] == root) {
                        root = sibling;
                    } else {
                        set_child(path_stack[depth - 2], dir_stack[depth - 2], sibling);
                    }
                    break;
                }
            } else {
                // parent is right child
                sibling = path_stack[depth - 1]->left;
                if (!sibling)
                    break;

                if (sibling->color == RED) {
                    path_stack[depth - 1]->color = RED;
                    sibling->color = BLACK;
                    path_stack[depth - 1]->left = sibling->right;
                    sibling->right = path_stack[depth - 1];

                    if (path_stack[depth - 1] == root) {
                        root = sibling;
                    } else {
                        set_child(path_stack[depth - 2], dir_stack[depth - 2], sibling);
                    }

                    dir_stack[depth] = DIR_RIGHT;
                    path_stack[depth] = path_stack[depth - 1];
                    path_stack[depth - 1] = sibling;
                    depth++;

                    sibling = path_stack[depth - 1]->left;
                }

                if (!sibling)
                    break;

                if ((!sibling->left || sibling->left->color == BLACK) &&
                    (!sibling->right || sibling->right->color == BLACK)) {
                    sibling->color = RED;
                } else {
                    if (!sibling->left || sibling->left->color == BLACK) {
                        nephew = sibling->right;
                        sibling->color = RED;
                        nephew->color = BLACK;
                        sibling->right = nephew->left;
                        nephew->left = sibling;
                        sibling = path_stack[depth - 1]->left = nephew;
                    }

                    sibling->color = path_stack[depth - 1]->color;
                    path_stack[depth - 1]->color = BLACK;
                    sibling->left->color = BLACK;
                    path_stack[depth - 1]->left = sibling->right;
                    sibling->right = path_stack[depth - 1];

                    if (path_stack[depth - 1] == root) {
                        root = sibling;
                    } else {
                        set_child(path_stack[depth - 2], dir_stack[depth - 2], sibling);
                    }
                    break;
                }
            }

            depth--;
        }
    } else {
        // Deleted/red-replaced node was red → no further action.
    }
}

/* ------------------------------------------------------------
 * Traversal & Search
 * ------------------------------------------------------------ */

void inorderTraversal(struct rbNode* node) {
    if (node) {
        inorderTraversal(node->left);
        if (node->color == RED) {
            printf("%d(RED) ", node->data);
        } else {
            printf("%d(BLACK) ", node->data);
        }
        inorderTraversal(node->right);
    }
}

// (Unused for now, kept for future use as requested)
void searchNode(struct rbNode* node, int val, bool* found) {
    if (node) {
        searchNode(node->left, val, found);
        if (node->data == val) {
            printf(node->color == RED ? "red\n" : "black\n");
            *found = true;
            return;
        }
        searchNode(node->right, val, found);
    }
}

// iterative binary search on RB tree (used by main)
void binarySearchNode(struct rbNode* node, int val) {
    while (node) {
        if (node->data == val) {
            printf(node->color == RED ? "red\n" : "black\n");
            return;
        }
        node = (val < node->data) ? node->left : node->right;
    }
    printf("Not found\n");
}

int main(int argc, char** argv) {
    char operation[10];
    int value;

    // 逐次讀一個「字串」命令
    while (scanf("%9s", operation) == 1) {
        if (strcmp(operation, "quit") == 0) {
            break;
        } else if (strcmp(operation, "insert") == 0) {
            if (scanf("%d", &value) != 1) {
                fprintf(stderr, "invalid input for insert\n");
                return 1;
            }
            insertion(value);
        } else if (strcmp(operation, "delete") == 0) {
            if (scanf("%d", &value) != 1) {
                fprintf(stderr, "invalid input for delete\n");
                return 1;
            }
            deletion(value);
        } else if (strcmp(operation, "search") == 0) {
            if (scanf("%d", &value) != 1) {
                fprintf(stderr, "invalid input for search\n");
                return 1;
            }

            binarySearchNode(root, value);

        } else if (strcmp(operation, "print") == 0) {
            inorderTraversal(root);
            printf("\n");
        } else {
            // 未知指令：清掉該行殘餘輸入，或提示錯誤
            fprintf(stderr, "unknown op: %s\n", operation);
        }
    }
    return 0;
}
