class solution{
    public: 
    ListNode* deleteDuplicates(ListNode* head){
        ListNode *ptr = head;

        while(head && head->next){ // i.e loop run while head and head->next is not null
            if(head->val == head->next->val){ // i.e if current node value is equal to next node value
                head->next = head->next->next; // then we will skip the next node by pointing current node to next of next node
            }
            else{
                head = head->next; // else we will move to next node
            }

        }
        return ptr; // finally we will return the pointer to head of the linked list
    }
}