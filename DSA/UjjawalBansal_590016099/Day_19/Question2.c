#include <stdio.h>
#include <stdlib.h>

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

// Funtion to find middle by using slow and fast pointers
struct Node* find_middle(struct Node* head) {
    struct Node* slow = head;
    struct Node* fast = head;

    while (fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

//Function to print a Linked List
void print_list(struct Node* head) {
    if (head == NULL) {
        printf("NULL\n");
        return;
    }
    while (head->next != NULL) {
        printf("%d -> ", head->val);
        head = head->next;
    }
    printf("%d\n", head->val);
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

    printf("Original Linked List:\n");
    print_list(head);

    struct Node* middle = find_middle(head);

    if (middle == NULL) printf("Linked list is empty, so no middle value, middle node = NULL");
    else printf("Middle Node Value: %d", middle->val);
    return 0;
}