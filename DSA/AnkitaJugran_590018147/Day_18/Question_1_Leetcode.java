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
class Solution {
    public ListNode rotateRight(ListNode head, int k) {
        
        //if list is empty or have one node or k is zero means no rotation
        if (head == null || head.next == null || k == 0) {
            return head;
        }

        int length = 1;
        ListNode tail = head;

        //count the length of linked list
        while (tail.next != null) {
            length++;
            tail = tail.next;
            }
        
        //reduce the unnecessary rotations
        k = k % length;

        if ( k == 0 ){
            return head;
        }

        //no. of steps to reach new tail
        int steps = length - k - 1;

        ListNode new_tail = head;

        while ( steps > 0 ){
            new_tail = new_tail.next;
            steps--;
        }

        //new head postion
        ListNode new_head = new_tail.next;

        //making list cirular
        tail.next = head;

        //breaking the list from new tail
        new_tail.next = null;

        return new_head;

    }
}