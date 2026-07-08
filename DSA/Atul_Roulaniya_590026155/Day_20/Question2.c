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

void display(){

    struct node *temp = head;

    while(temp != NULL){
        printf("%d", temp->data);
        temp = temp->next;
        if(temp != NULL){
            printf("->");
        }
    }
    printf("\n");

}
