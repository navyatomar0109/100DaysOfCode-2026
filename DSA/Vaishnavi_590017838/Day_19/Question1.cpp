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

Node* removeDuplicates(Node* head) {
    if(head == nullptr)
        return head;
    Node* current = head;
    while(current != nullptr && current->next != nullptr) {
        if(current->data == current->next->data) {
            Node* duplicate = current->next;
            current->next = duplicate->next;
            delete duplicate;
        }
        else {
            current = current->next;
        }
    }
    return head;
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
    cout << "Enter the sorted linked list: ";
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
    head = removeDuplicates(head);
    cout << "Linked list after removing duplicates: ";
    printList(head);
    return 0;
}
