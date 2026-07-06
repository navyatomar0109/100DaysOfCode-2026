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
    public ListNode swapPairs(ListNode head) {
        ListNode d = new ListNode(0);
        d.next = head;

        ListNode p = d;

        while (p.next != null && p.next.next != null) {
            ListNode a = p.next;
            ListNode b = a.next;

            a.next = b.next;
            b.next = a;
            p.next = b;

            p = a;
        }

        return d.next;
    }
}