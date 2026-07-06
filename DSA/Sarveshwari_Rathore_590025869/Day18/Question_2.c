#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;
    struct node *next;
};
struct node *newNode(int data) {
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = data;
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
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}
struct node *deleteNthfromend(struct node *head, int n) {
    if (head == NULL)
        return NULL;
    struct node *fast = head;
    struct node *slow = head;
    // moving fast n steps ahead
    for (int i = 0; i < n; i++) {
        fast = fast->next;
    }
    // delete the head node
    if (fast == NULL) {
        struct node *temp = head;
        head = head->next;
        free(temp);
        return head;
    }
    while (fast->next != NULL) {
        fast = fast->next;
        slow = slow->next;
    }
    // delete nth node from the end
    struct node *del = slow->next;
    slow->next = del->next;
    free(del);
    return head;
}
int main(){
    int n,m;
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    struct node *head = createList(n);
    printf("Original List: ");
    display(head);
    printf("Enter nth node:");
    scanf("%d", &m);
    head = deleteNthfromend(head, m);
    printf("Updated List: ");
    display(head);
    return 0;
}