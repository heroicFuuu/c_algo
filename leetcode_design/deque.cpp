class Node {
  public:
    int val;
    Node* next;
    Node* prev;
    Node(int v) {
        next = this;
        prev = this;
        val = v;
    }
};

class MyCircularDeque {
    int capacity;
    int curNodes;
    Node* head;

  public:
    MyCircularDeque(int k) {
        capacity = k;
        curNodes = 0;
        head = new Node(0);
    }

    bool insertFront(int value) {
        if (isFull())
            return false;
        Node* p = new Node(value);

        p->next = head->next;
        head->next->prev = p;

        head->next = p;
        p->prev = head;

        ++curNodes;
        return true;
    }

    bool insertLast(int value) {
        if (isFull())
            return false;
        Node* p = new Node(value);
        p->prev = head->prev;
        head->prev->next = p;

        head->prev = p;
        p->next = head;

        ++curNodes;
        return true;
    }

    bool deleteFront() {
        if (isEmpty())
            return false;
        Node* p = head->next;

        head->next = p->next;
        p->next->prev = head;

        delete (p);
        --curNodes;
        return true;
    }

    bool deleteLast() {
        if (isEmpty())
            return false;

        Node* p = head->prev;

        head->prev = p->prev;
        p->prev->next = head;

        delete (p);
        --curNodes;
        return true;
    }

    int getFront() {
        if (isEmpty())
            return -1;
        return head->next->val;
    }

    int getRear() {
        if (isEmpty())
            return -1;
        return head->prev->val;
    }

    bool isEmpty() {
        return curNodes == 0;
    }

    bool isFull() {
        return curNodes == capacity;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */