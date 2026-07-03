#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int value) {
        data = value;
        next = nullptr;
    }
};

Node* rotateRight(Node* head, int k) {
    if(head == nullptr || head->next == nullptr || k == 0)
        return head;
    int length = 1;
    Node* tail = head;
    while(tail->next != nullptr) {
        tail = tail->next;
        length++;
    }
    k %= length;
    if(k == 0)
        return head;

    tail->next = head;
    int steps = length - k;
    Node* newTail = head;
    for(int i = 1; i < steps; i++)
        newTail = newTail->next;
    Node* newHead = newTail->next;
    newTail->next = nullptr;
    return newHead;
}
void printList(Node* head) {
    while(head != nullptr) {
        cout << head->data;
        if(head->next != nullptr)
            cout << " -> ";
        head = head->next;
    }
    cout << endl;
}
int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    int k = 2;
    head = rotateRight(head, k);
    printList(head);
    return 0;
}
