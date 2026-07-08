#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node* createNode(int data) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

bool hasCycle(struct Node *head) {
    struct Node *visited[10000];
    int count = 0;

    while (head != NULL) {
        for (int i = 0; i < count; i++) {
            if (visited[i] == head)
                return true;
        }

        visited[count++] = head;
        head = head->next;
    }

    return false;
}

int main() {
    int n, pos;
    struct Node *head = NULL, *tail = NULL;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    struct Node *nodes[1000];

    printf("Enter node values: ");
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);

        nodes[i] = createNode(x);

        if (head == NULL)
            head = tail = nodes[i];
        else {
            tail->next = nodes[i];
            tail = nodes[i];
        }
    }

    printf("Enter position (-1 for no cycle): ");
    scanf("%d", &pos);

    if (pos != -1)
        tail->next = nodes[pos];

    if (hasCycle(head))
        printf("true\n");
    else
        printf("false\n");

    return 0;
}
