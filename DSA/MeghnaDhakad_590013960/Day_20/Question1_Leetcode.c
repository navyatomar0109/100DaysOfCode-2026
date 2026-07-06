/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
struct ListNode* removeElements(struct ListNode* head, int val) {

    struct ListNode dummy;
    dummy.next = head;

    struct ListNode* curr = &dummy;

    while (curr->next) {

        if (curr->next->val == val) {
            curr->next = curr->next->next;
        } else {
            curr = curr->next;
        }
    }

    return dummy.next;
}