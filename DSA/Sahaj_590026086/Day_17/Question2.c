#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
struct Node{
    int data;
    struct Node* next;
};
bool cycle(struct Node *head){
    struct Node *slow=head, *fast=head;
    while(fast&&fast->next){
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast)
          return true;
    }
    return false;
}
int main(){
    int n, pos;
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    struct Node *head=NULL,*temp=NULL,*nodes[n];
    for(int i=0;i<n;i++){
        nodes[i]=(struct Node*)malloc(sizeof(struct Node));
        scanf("%d", &nodes[i]->data);
        nodes[i]->next = NULL;
        if(i>0)
          nodes[i-1]->next=nodes[i];
    }
    head=nodes[0];
    printf("Enter position to create cycle (-1 for no cycle): ");
    scanf("%d", &pos);
    if(pos!=-1){
        nodes[n-1]->next = nodes[pos];
    }
    if(cycle(head))
        printf("true\n");
    else
        printf("false\n");
    return 0;
}
