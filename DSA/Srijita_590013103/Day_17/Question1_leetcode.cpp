/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* reverse(ListNode* head) {
        ListNode* prev = nullptr;

        while (head != nullptr) {
            ListNode* nextNode = head->next;
            head->next = prev;
            prev = head;
            head = nextNode;
        }

        return prev;
    }
    bool isPalindrome(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return true;
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* secondHalf = reverse(slow);
        ListNode* secondHalfCopy = secondHalf;
        ListNode* firstHalf = head;
        bool palindrome = true;
        while (secondHalf != nullptr) {
            if (firstHalf->val != secondHalf->val) {
                palindrome = false;
                break;
            }

            firstHalf = firstHalf->next;
            secondHalf = secondHalf->next;
        }
        reverse(secondHalfCopy);
        return palindrome;
    }
};