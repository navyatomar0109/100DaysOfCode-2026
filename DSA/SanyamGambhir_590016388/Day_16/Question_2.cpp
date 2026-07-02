#include <iostream>

// Definition for singly-linked list node.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        // If the list is empty or has only one node, a cycle is impossible
        if (head == nullptr || head->next == nullptr) {
            return false;
        }
        
        ListNode *slow = head;
        ListNode *fast = head;
        
        // Move fast by two steps and slow by one step
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
            
            // If they meet, there is a cycle
            if (slow == fast) {
                return true;
            }
        }
        
        // If fast reaches the end, no cycle exists
        return false;
    }
};