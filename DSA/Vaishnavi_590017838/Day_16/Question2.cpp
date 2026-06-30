#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
    Node(int value) {
        data = value;
        prev = NULL;
        next = NULL;
    }
};

Node* deleteLastNode(Node* head) {
    if(head == NULL)
        return NULL;
    if(head->next == NULL) {
        delete head;
        return NULL;
    }

    Node* current = head;
    while(current->next != NULL) {
        current = current->next;
    }
    current->prev->next = NULL;
    delete current;
    return head;
}

void printList(Node* head) {
    while(head != NULL) {
        cout << head->data;
        if(head->next != NULL)
            cout << " <-> ";
        head = head->next;
    }
    cout << endl;
}
int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->prev = head;
    head->next->next = new Node(3);
    head->next->next->prev = head->next;
    head->next->next->next = new Node(4);
    head->next->next->next->prev = head->next->next;
    cout << "Original List: ";
    printList(head);
    head = deleteLastNode(head);
    cout << "Updated List: ";
    printList(head);
    return 0;
}
