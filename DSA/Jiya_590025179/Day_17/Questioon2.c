#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct node* createnode(int value) {
    struct node* n = (struct node*)malloc(sizeof(struct node));
    n->data = value;
    n->next = NULL;
    return n;
}

struct node* insertlast(struct node* head, int value) {
    struct node* newnode = createnode(value);

    if (head == NULL)
        return newnode;

    struct node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newnode;
    return head;
}

int cycle(struct node* head) {
    struct node* slow = head;
    struct node* fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
            return 1;
    }

    return 0;
}

int main() {
    struct node* head = NULL;
    int value;
    char choice;

    do {
        printf("Enter value: ");
        scanf("%d", &value);
        head = insertlast(head, value);

        printf("Add another node? (Y/N): ");
        scanf(" %c", &choice);

    } while (choice == 'Y' || choice == 'y');

    int pos;
    printf("Enter position to create cycle (-1 for no cycle): ");
    scanf("%d", &pos);

    if (pos != -1) {
        struct node* last = head;
        struct node* cycleNode = NULL;
        int index = 0;

        while (last->next != NULL) {
            if (index == pos)
                cycleNode = last;

            last = last->next;
            index++;
        }

        if (index == pos)
            cycleNode = last;

        if (cycleNode != NULL)
            last->next = cycleNode;
    }

    if (cycle(head))
        printf("true\n");
    else
        printf("false\n");

    return 0;
}
