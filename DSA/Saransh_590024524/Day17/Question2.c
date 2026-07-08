#include <stdbool.h>

struct LinkNode {
    int val;
    struct LinkNode* next;
};
bool hascycle(struct ListNode* head)
(
    struct ListNode* slow = head;
    struct ListNode* fast = head;

    while (fast != NULL && fast->next !- NULL)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (fast == slow)
            return true;
    }
    return false;
)