#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

Node* segregateEvenOdd(Node* head) {
    if (head == NULL)
        return head;

    Node *evenStart = NULL, *evenEnd = NULL;
    Node *oddStart = NULL, *oddEnd = NULL;

    Node* curr = head;

    while (curr != NULL) {
        if (curr->data % 2 == 0) {
            if (evenStart == NULL)
                evenStart = evenEnd = curr;
            else {
                evenEnd->next = curr;
                evenEnd = curr;
            }
        } else {
            if (oddStart == NULL)
                oddStart = oddEnd = curr;
            else {
                oddEnd->next = curr;
                oddEnd = curr;
            }
        }
        curr = curr->next;
    }

    if (evenStart == NULL || oddStart == NULL)
        return head;

    evenEnd->next = oddStart;
    oddEnd->next = NULL;

    return evenStart;
}

void printList(Node* head) {
    while (head != NULL) {
        cout << head->data;
        if (head->next != NULL)
            cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    // Linked List: 17 -> 15 -> 8 -> 9 -> 2 -> 4 -> 6
    Node* head = new Node(17);
    head->next = new Node(15);
    head->next->next = new Node(8);
    head->next->next->next = new Node(9);
    head->next->next->next->next = new Node(2);
    head->next->next->next->next->next = new Node(4);
    head->next->next->next->next->next->next = new Node(6);

    cout << "Original List: ";
    printList(head);

    head = segregateEvenOdd(head);

    cout << "Updated List: ";
    printList(head);

    return 0;
}