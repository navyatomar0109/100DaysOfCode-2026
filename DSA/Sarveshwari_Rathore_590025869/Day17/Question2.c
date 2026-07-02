#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
struct node{
    int val;
    struct node* next;
};
struct node* newNode(int data) {
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp->val = data;
    temp->next = NULL;
    return temp;
}
bool hascycle(struct node *head){
    struct node *slow = head;
    struct node *fast = head;
    while(fast != NULL && fast -> next != NULL){
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast){
            return true;
        }
    } return false;
}
int main(){
    struct node *head = newNode(10);
    head->next = newNode(20);
    head->next->next = newNode(30);
    head->next->next->next = newNode(40);
    head->next->next->next->next = head->next;

    if (hascycle(head))
        printf("cycle exists");
    else
        printf("no cycle exists");
}