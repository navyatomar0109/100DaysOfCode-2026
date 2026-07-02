class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* previous = nullptr;
        ListNode* current = head;
        while(current != nullptr) {
            ListNode* nextNode = current->next;
            current->next = previous;
            previous = current;
            current = nextNode;
        }
        return previous;
    }
    bool isPalindrome(ListNode* head) {
        if(head == nullptr || head->next == nullptr)
            return true;
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast->next != nullptr && fast->next->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* secondHalf = reverseList(slow->next);
        ListNode* firstHalf = head;
        ListNode* temp = secondHalf;
        while(temp != nullptr) {
            if(firstHalf->val != temp->val)
                return false;
            firstHalf = firstHalf->next;
            temp = temp->next;
        }
        return true;
    }
};
