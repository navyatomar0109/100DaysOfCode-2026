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

Node* segregate(Node* head) {
    if(head == nullptr || head->next == nullptr)
        return head;
    Node *evenStart = nullptr, *evenEnd = nullptr;
    Node *oddStart = nullptr, *oddEnd = nullptr;
    Node* current = head;
    while(current != nullptr) {
        if(current->data % 2 == 0) {
            if(evenStart == nullptr) {
                evenStart = current;
                evenEnd = current;
            }
            else {
                evenEnd->next = current;
                evenEnd = current;
            }
        }
        else {
            if(oddStart == nullptr) {
                oddStart = current;
                oddEnd = current;
            }
            else {
                oddEnd->next = current;
                oddEnd = current;
            }
        }
        current = current->next;
    }
    if(evenStart == nullptr || oddStart == nullptr)
        return head;
    evenEnd->next = oddStart;
    oddEnd->next = nullptr;
    return evenStart;
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
    int n;
    cout << "Enter the number of nodes: ";
    cin >> n;
    Node* head = nullptr;
    Node* tail = nullptr;
    cout << "Enter the elements: ";
    for(int i = 0; i < n; i++) {
        int value;
        cin >> value;
        Node* newNode = new Node(value);
        if(head == nullptr) {
            head = newNode;
            tail = newNode;
        }
        else {
            tail->next = newNode;
            tail = newNode;
        }
    }
    head = segregate(head);
    cout << "Rearranged linked list: ";
    printList(head);
    return 0;
}
