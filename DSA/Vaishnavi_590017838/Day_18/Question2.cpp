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

Node* removeNthFromEnd(Node* head, int n) {
    if (head == nullptr)
        return nullptr;
    int length = 0;
    Node* current = head;
    while (current != nullptr) {
        length++;
        current = current->next;
    }

    if (n > length || n <= 0) {
        cout << "Invalid position!" << endl;
        return head;
    }

    if (n == length) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return head;
    }

    current = head;
    for (int i = 1; i < length - n; i++)
        current = current->next;
    Node* nodeToDelete = current->next;
    current->next = nodeToDelete->next;
    delete nodeToDelete;
    return head;
}

void printList(Node* head) {
    if (head == nullptr) {
        cout << "List is empty." << endl;
        return;
    }

    while (head != nullptr) {
        cout << head->data;
        if (head->next != nullptr)
            cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    int size;
    cout << "Enter the number of nodes: ";
    cin >> size;
    Node* head = nullptr;
    Node* tail = nullptr;
    cout << "Enter the elements of the linked list: ";
    for (int i = 0; i < size; i++) {
        int value;
        cin >> value;
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }
    int n;
    cout << "Enter the position from the end to remove: ";
    cin >> n;
    head = removeNthFromEnd(head, n);
    cout << "Updated linked list: ";
    printList(head);
    return 0;
}
