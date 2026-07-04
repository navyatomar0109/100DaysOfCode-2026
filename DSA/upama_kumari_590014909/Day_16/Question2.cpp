#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;

    Node(int val) {
        data = val;
        prev = NULL;
        next = NULL;
    }
};

Node* deleteLastNode(Node* head) {
    if (head == NULL)
        return NULL;

    if (head->next == NULL) {
        delete head;
        return NULL;
    }

    Node* temp = head;

    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->prev->next = NULL;
    delete temp;

    return head;
}

void printList(Node* head) {
    if (head == NULL) {
        cout << "NULL";
        return;
    }

    while (head != NULL) {
        cout << head->data;
        if (head->next != NULL)
            cout << " <-> ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    Node* head = new Node(1);
    Node* second = new Node(2);
    Node* third = new Node(3);
    Node* fourth = new Node(4);

    head->next = second;
    second->prev = head;

    second->next = third;
    third->prev = second;

    third->next = fourth;
    fourth->prev = third;

    cout << "Original List: ";
    printList(head);

    head = deleteLastNode(head);

    cout << "After Deleting Last Node: ";
    printList(head);

    return 0;
}