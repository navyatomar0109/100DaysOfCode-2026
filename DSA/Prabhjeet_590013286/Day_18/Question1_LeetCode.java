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

//Rotate the list k times to the right

class Solution {

    public ListNode rotateRight(ListNode head, int k) {

        if (head == null || head.next == null || k == 0) {
            return head;
        }

        int length = 1;
        ListNode tail = head;

        // finding the last node and total length
        while (tail.next != null) {
            tail = tail.next;
            length++;
        }

        // rotating length times gives the same list
        k = k % length;

        if (k == 0) {
            return head;
        }

        // joining the last node back to the head
        tail.next = head;

        int steps = length - k;
        ListNode newTail = tail;

        // walk till the new tail
        while (steps-- > 0) {
            newTail = newTail.next;
        }

        // break the circle from here
        ListNode newHead = newTail.next;
        newTail.next = null;

        return newHead;
    }
}