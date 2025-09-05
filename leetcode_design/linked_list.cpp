class Node{
public:
    int val;
    Node* next;
    Node* prev;
    Node(int value): val(value), next(this), prev(this){};

};

class MyLinkedList {
public:
    int lens;
    Node* head;
    MyLinkedList() {
        lens = 0;
        head = new Node(0);
    }
    
    int get(int index) {
        if (index < 0 || index >= lens) return -1;
        //
        Node* p = head->next;

        for (int i = 0; i < index ; i++) p = p->next;

        return p->val;
    }
    
    void addAtHead(int val) {
        Node* p = new Node(val);
        head->next->prev = p ;
        p->next          = head->next;

        head->next = p;
        p->prev    = head;
        
        lens++; 
        
    }
    
    void addAtTail(int val) {
        Node* p = new Node(val);
        head->prev->next = p;
        p->prev = head->prev;

        head->prev = p;
        p->next = head;
        lens ++;
        
    }
    
    void addAtIndex(int index, int val) {
        if (index > lens) return ;
        if (index == lens) {
            addAtTail(val);
            return ;
        }
        
        Node* newNode = new Node(val);

        Node* p = head->next;
        for (int i = 0; i < index ; i++) p = p->next;
        p->prev->next = newNode;
        newNode->prev = p->prev;

        p->prev = newNode;
        newNode->next = p;
        lens++;
    }
    
    void deleteAtIndex(int index) {
        if (index < 0 || index >= lens) return;
        Node* p = head->next;
        for (int i = 0; i < index ; i++) p = p->next;
        p->prev->next = p->next;
        p->next->prev = p->prev;

        delete(p);
        
        lens--;

    }
};
