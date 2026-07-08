#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};

struct node *head = NULL;

void insert(int value){
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

int main(){
    
    int i, n, value;
    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter elements: ");
    for(i = 0; i < n; i++){
        scanf("%d", &value);
        insert(value);
    }

    struct node *slow = head;
    struct node *fast = head;

    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }

    if(slow != NULL){
        printf("%d", slow->data);
    }else{
        printf("NULL");
    }
    return 0;
}