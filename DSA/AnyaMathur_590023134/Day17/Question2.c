/* Problem 2 
Detect Cycle in a Linked List */

#include <stdio.h>
#include <stdlib.h>

struct Node{
    int value;
    struct Node *next;
};

struct Node* createnode(int value){
    struct Node *newnode = (struct Node*)malloc(sizeof(struct Node));
    newnode->value = value;
    newnode->next = NULL;
    return newnode;
}

int hascycle(struct Node *head){
    if (head == NULL || head->next == NULL){
        return 0;
    }
    struct Node *slow = head;
    struct Node *fast = head;
    while (fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast){
            return 1;
        }
    }
    return 0;
}

int main(){
    int n;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    struct Node *head = NULL;
    struct Node *tail = NULL;
    struct Node *nodes[n];

    printf("Enter the values of the nodes: ");
    for (int i = 0; i < n; i++){
        int value;
        scanf("%d", &value);
        nodes[i] = createnode(value);
        if (head == NULL){
            head = nodes[i];
            tail = nodes[i];
        }
        else{
            tail->next = nodes[i];
            tail = nodes[i];
        }
    }
    int pos;

    printf("Enter position: ");
    scanf("%d", &pos);

    if (pos != -1){
        tail->next = nodes[pos];
    }

    if (hascycle(head)){
        printf("true");
    }
    else{
        printf("false");
    }
    return 0;
}