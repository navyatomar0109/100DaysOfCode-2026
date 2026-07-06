#include <iostream>

// Definition for Doubly Linked List Node
struct Node {
    int data;
    Node* next;
    Node* prev;

    Node(int val) {
        data = val;
        next = nullptr;
        prev = nullptr;
    }
};

// Function to delete the last node
Node* deleteLastNode(Node* head) {
    // Edge Case 1: If the list is already empty
    if (head == nullptr) {
        return nullptr;
    }

    // Edge Case 2: If there is only one node in the list
    if (head->next == nullptr) {
        delete head;
        return nullptr;
    }

    // Step 1: Traverse to the last node
    Node* curr = head;
    while (curr->next != nullptr) {
        curr = curr->next;
    }

    // Step 2: Disconnect the last node from the second-to-last node
    Node* secondLast = curr->prev;
    secondLast->next = nullptr;

    // Step 3: Free the memory of the last node
    delete curr;

    // Return the unchanged head of the list
    return head;
}