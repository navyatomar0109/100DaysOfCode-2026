#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Base node structure
struct Node {
    int val;
    struct Node* next;
};

// Function to create a new node
struct Node* create_node(int val) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->val = val;
    new_node->next = NULL;
    return new_node;
}

// boolean function to detect a cycle
bool cycle(struct Node* head) {
    struct Node* p1 = head;
    struct Node* p2 = head;

    //Using Slow and Fast two pointers technique
    while (p2 && p2->next) {
        p1 = p1->next;
        p2 = p2->next->next;
        if (p1 == p2) return true;
    }
    return false;
}

// Function to add a new node to the list
struct Node* add_node(struct Node* head, int val) {
    struct Node* new_node = create_node(val);
    
    // For empty list, return the new_node
    if (head == NULL) {
        return new_node;
    }
    
    // Travel to the last node of the list
    struct Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    
    // Append the new node to the end of the list
    temp->next = new_node;
    
    // Return the head
    return head;
}

int main() {
    int n;
    printf("Enter the number of Nodes in the Linked List: ");
    scanf("%d", &n);

    struct Node* head = NULL;
    int val;
    if (n>0) {
        printf("Enter %d integers: ", n);
        for (int i = 0; i<n; i++){
            scanf("%d", &val);
            head = add_node(head, val);
        }
    }
    
    int pos;
    printf("Enter the index of the node that the last node points to (-1 if it points to NULL): ");
    scanf("%d", &pos);

    if (pos >= 0 && pos < n && head != NULL) {

        struct Node* tail = head;
        while (tail->next != NULL) {
            tail = tail->next;
        }
        int a = 0;
        struct Node* cur = head;
        while (a != pos) {
            a++;
            cur = cur->next;
        }
        tail->next = cur;
    }
    bool ans = cycle(head);
    printf("Contains Cycle: %s", ans ? "true" : "false");
}