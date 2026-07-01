/*Detect Cycle in a Linked List
Explanation
Determine whether a singly linked list contains a cycle (loop); return true if a cycle exists, otherwise return false. Here, pos represents the index of the node that the last node points to (-1 means the last node points to NULL).*/

#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};

struct node *head = NULL;

void insertEnd(int value){
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = value;
    ptr->next = NULL;

    if(head == NULL){
        head = ptr;
        return;
    }

    struct node *temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }

    temp->next = ptr;
}

int cycle(struct node *head){
    struct node *slow = head;
    struct node *fast = head;

    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast){
            return 1;
        }
    }

    return 0;
}

int main(){
    int n, value, pos, i;
    struct node *last, *temp;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter node values: ");
    for(i = 0; i < n; i++){
        scanf("%d", &value);
        insertEnd(value);
    }

    printf("Enter position to form cycle (-1 for no cycle): ");
    scanf("%d", &pos);

    if(pos >= 0 && pos < n){

        last = head;
        while(last->next != NULL){
            last = last->next;
        }

        temp = head;
        for(i = 0; i < pos; i++){
            temp = temp->next;
        }
        
        last->next = temp;
    }


    if(cycle(head) == 1){
        printf("true");
    }else{
        printf("false");
    }

    return 0;
}