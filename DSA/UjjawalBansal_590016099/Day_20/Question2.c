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

struct Node* rearrange_list(struct Node* head) {
    // Handle edge cases: empty list or single node
    if (!head || !head->next) return head;
    
    // Dummy nodes to anchor the start of our two new lists
    struct Node even;
    struct Node odd;
    even.next = NULL;
    odd.next = NULL;
    
    // Tail pointers used to build the even and odd chains
    struct Node* a = &even;
    struct Node* b = &odd;
    
    struct Node* current = head;
    
    while (current) {
        // Route even values to the 'a' chain
        if (current->val % 2 == 0) {
            a->next = current;
            a = a->next;
        }
        // Route odd values to the 'b' chain
        else {
            b->next = current;
            b = b->next;
        }
        current = current->next;
    }
    
    // Connect the end of the even chain to the start of the odd chain
    a->next = odd.next;
    
    // Cap the odd chain with NULL to prevent infinite cycles
    b->next = NULL;

    return even.next;
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

    struct Node* ans = rearrange_list(head);

    printf("Linked List after rearranging it:\n");
    print_list(ans);
    return 0;
}