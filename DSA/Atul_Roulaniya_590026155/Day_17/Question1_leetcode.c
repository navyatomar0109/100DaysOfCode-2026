bool isPalindrome(struct ListNode* head){
    
    if(head == NULL || head->next == NULL){
        return true;
    }

    struct ListNode *slow = head, *fast = head;

    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
    }

    struct ListNode *prev = NULL, *curr = slow, *ptr = NULL;

    while(curr){
        ptr = curr->next;
        curr->next = prev;
        prev = curr;
        curr = ptr;
    }

    struct ListNode *ptr1 = head;
    struct ListNode *ptr2 = prev;

    while(ptr2){
        if(ptr1->val != ptr2->val){
            return false;
        }
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }

    return true; 
}