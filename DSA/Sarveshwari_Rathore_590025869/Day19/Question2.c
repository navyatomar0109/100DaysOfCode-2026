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
struct node *middlenode(struct node *head){
     if (head == NULL)
        return NULL;
    struct node *slow = head;
    struct node *fast = head;
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}
int main(){
    int n;
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    struct node *head = createList(n);
    printf("Original List:\n");
    display(head);
    printf("%d",middlenode(head) -> val);
    return 0;
}