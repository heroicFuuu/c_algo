#include <iostream>
#include <vector>

using std::vector;

    
class Node{
public:
	int num ;
	Node * next;
	Node (int val){
	num = val;
	next = NULL;
    }
};

void InsertNode(int num, Node* &head){// or p2p
	if (head == NULL){ 
        head = new Node(num);
        return;
    }

    Node* cur = head;
	
	while (cur->next != NULL) cur = cur->next;
	
	cur->next = new Node(num);// -> next 警告

    return ;
}

void PrintList(Node* &head) {
    Node* cur = head;
    while (cur != NULL) {
        std::cout << cur->num << " ";
        cur = cur->next;
    }
    std::cout << std::endl;
}

int main(){

	vector<int> arr {1,2,3,4,5,6};
    int n =arr.size();
    Node *head = NULL;

    for (int i = 0; i < n; i++){
        InsertNode(arr[i], head);	
    }
    PrintList(head);
	return 0;
}
