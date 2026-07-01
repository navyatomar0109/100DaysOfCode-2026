#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
};
struct Node* createNode(int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = NULL;
    return newNode;
}
struct Node* buildList(int arr[], int n, int pos) {
    if (n == 0) return NULL;
    struct Node** nodes = (struct Node**)malloc(n * sizeof(struct Node*));
    for (int i = 0; i < n; i++)
        nodes[i] = createNode(arr[i]);
    for (int i = 0; i < n - 1; i++)
        nodes[i]->next = nodes[i + 1];
    if (pos != -1)
        nodes[n - 1]->next = nodes[pos];
    else
        nodes[n - 1]->next = NULL;

    struct Node* head = nodes[0];
    free(nodes); 
    return head;
}
int hasCycle(struct Node* head) {
    if (head == NULL || head->next == NULL) return 0;
    struct Node* slow = head;
    struct Node* fast = head;
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
            return 1;
    }
    return 0;
}
int main() {
    int n;
    scanf("%d", &n);
    int* arr = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    int pos;
    scanf("%d", &pos);
    struct Node* head = buildList(arr, n, pos);
    printf("%s\n", hasCycle(head) ? "true" : "false");
    free(arr);
    return 0;
}