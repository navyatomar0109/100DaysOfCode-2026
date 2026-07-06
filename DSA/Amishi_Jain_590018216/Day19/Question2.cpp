// (876) leetcode Middle of the Linked List solve using  Slow and Fast Pointer technique 
// When the fast pointer reaches the end of the linked list, the slow pointer will be at the middle.
//If there are two middle nodes, the slow pointer automatically points to the second middle node,

#include<iostream>
using namespace std;

struct Node{
        int data;
        Node *next;
};

Node* middlenode(Node* head){
    Node *slow = head;
    Node *fast = head;

    while(fast != NULL && fast->next!= NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

int main(){
    Node *head = new Node{1};
    head->next = new Node{2};
    head->next->next = new Node{3};
    head->next->next->next = new Node{4};
    head->next->next->next->next = new Node{5};
   // head->next->next->next->next->next = new Node{6}; // with this midlle node value will be 4 as there are two middle nodes 3 and 4, and the second middle node is returned.

    Node* middle = middlenode(head);

    cout << "Middle node value: " << middle->data << endl;
    return 0;
}