#include <stdio.h>
#include <stdlib.h>
struct node {
    int  val;
    struct node *next;
};
struct node* newNode(int val) {
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp->val = val;
    temp->next = NULL;
    return temp;
}
struct node* createList(int n) {
    struct node *head = NULL;
    struct node *tail = NULL;
    int value;
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        struct node *temp = newNode(value);
        if (head == NULL) {
            head = temp;
            tail = temp;
        } else {
            tail->next = temp;
            tail = temp;
        }
    } return head;
}
void display(struct node *head) {
    while (head != NULL) {
        printf("%d -> ", head->val);
        head = head->next;
    } printf("NULL\n");
}
struct node *rearrange(struct node *head){
    if(head == NULL){
        return head;
    }
    struct node *tail=head;
    while(tail->next != NULL){
        tail = tail -> next;
    }  
    struct node *original_tail = tail;
    struct node temp;
    temp.next = head;
    struct node *prev = &temp;
    struct node *curr= head;

    while (curr != original_tail){
        if(curr -> val %2 != 0){
            struct node *Next = curr -> next;
            prev -> next = Next;
            tail -> next = curr;
            tail = curr;
            tail -> next = NULL;
            curr = Next;
        } else{
            prev = curr;
            curr = curr -> next;
        } 
    } return temp.next;
}
int main(){
    int n;
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    struct node *head = createList(n);
    printf("Original List:\n");
    display(head);
    head = rearrange(head);
    printf("Rearranged List:\n");
    display(head);
    return 0;
}