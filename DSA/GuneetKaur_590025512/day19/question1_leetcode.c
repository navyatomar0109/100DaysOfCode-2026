
  struct ListNode {
     int val;
     struct ListNode *next;
 };
 

struct ListNode* deleteDuplicates(struct ListNode* head) {
    if (head ==0)
        return 0;

    struct ListNode *prev = head;
    struct ListNode *temp = head->next;

    while (temp != 0) {

        if (temp->val == prev->val) {
            struct ListNode *duplicate = temp;
            temp = temp->next;
            free(duplicate);    
            continue;
        }

        prev->next = temp;       
        prev = temp;
        temp = temp->next;
    }

    prev->next = 0;           

    return head;
}