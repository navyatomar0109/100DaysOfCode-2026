/*Segregate Even and Odd Nodes in a Linked List
Explanation
Rearrange the existing linked list so that all even valued nodes appear before odd valued nodes while preserving their original order, without creating a new linked list, and print the modified linked list.*/

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

void segregate(){

    if(head == NULL || head->next == NULL){
        return;
    }

    struct node *last = head;
    while(last->next != NULL){
        last = last->next;
    }

    struct node *end = last;
    struct node *curr = head;
    struct node *prev = NULL;

    while(curr != last && curr->data % 2 != 0){
        end->next = curr;
        curr = curr->next;
        end = end->next;
        end->next = NULL;
    }

    if(curr->data % 2 == 0){
        head = curr;
        while(curr != last){

            if(curr->data % 2 == 0){
                prev = curr;
                curr = curr->next;
            }else{
                prev->next = curr->next;
                end->next = curr;
                end = curr;

                curr = prev->next;
                end->next = NULL;
            }
        }
    }else{
        prev = curr;
    }

    if(last->data % 2 != 0 && end != last){

        prev->next = end->next;
        end->next = last;
        end = last;
        end->next = NULL;
    }
}

int main(){

    int i, n, value;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter %d elements: ", n);

    for(i = 0; i < n; i++){
        scanf("%d", &value);
        insert(value);
    }

    printf("Linked List:\n");
    display();

    segregate();

    printf("Updated Linked List:\n");
    display();

    return 0;
}