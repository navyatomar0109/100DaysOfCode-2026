/**
 * Definition for singly-linked list.
 * public class ListNode {
 * int val;
 * ListNode next;
 * ListNode() {}
 * ListNode(int val) { this.val = val; }
 * ListNode(int val, ListNode next) { this.next = next; }
 * }
 */
class Solution {
    public ListNode removeElements(ListNode head, int val) {
        ListNode d = new ListNode(0);
        d.next = head;

        ListNode p = d;

        while (p.next != null) {
            if (p.next.val == val)
                p.next = p.next.next;
            else
                p = p.next;
        }

        return d.next;
    }
}