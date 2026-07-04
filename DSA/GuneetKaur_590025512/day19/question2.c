//middle of linked list 
//using slow fast approch 

struct Node {
    int val;
    struct Node *next;
};

struct Node* findMiddle(struct Node* head) {
    if (head == 0 || head->next == 0) {
        return head; 
    }
struct Node* slow=head;
struct Node* fast=head;

while (fast != 0 && fast->next != 0) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow; 
}