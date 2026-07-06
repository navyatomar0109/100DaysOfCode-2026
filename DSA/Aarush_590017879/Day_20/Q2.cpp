#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};

Node* segregateEvenOdd(Node* head) {
    if (head == nullptr)
        return head;

    Node *evenStart = nullptr, *evenEnd = nullptr;
    Node *oddStart = nullptr, *oddEnd = nullptr;

    Node* curr = head;

    while (curr != nullptr) {
        if (curr->data % 2 == 0) {
            if (evenStart == nullptr) {
                evenStart = evenEnd = curr;
            } else {
                evenEnd->next = curr;
                evenEnd = curr;
            }
        } else {
            if (oddStart == nullptr) {
                oddStart = oddEnd = curr;
            } else {
                oddEnd->next = curr;
                oddEnd = curr;
            }
        }
        curr = curr->next;
    }

    if (evenStart == nullptr)
        return oddStart;

    if (oddStart == nullptr)
        return evenStart;

    evenEnd->next = oddStart;
    oddEnd->next = nullptr;

    return evenStart;
}

void printList(Node* head) {
    while (head != nullptr) {
        cout << head->data;
        if (head->next != nullptr)
            cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    // Input: 17 -> 15 -> 8 -> 9 -> 2 -> 4 -> 6

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

    cout << "Modified List: ";
    printList(head);

    return 0;
}