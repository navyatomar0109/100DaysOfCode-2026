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
    public ListNode swapPairs(ListNode head) {
        
        //first creating a dummy node to keep track of starting of linkedlist
        ListNode dummy = new ListNode(-1);
        dummy.next = head;

        //creating prev to keep track of prev swapped pairs
        ListNode prev = dummy;

        while ( prev.next != null && prev.next.next != null ){

            ListNode first = prev.next;
            ListNode second = first.next;
            ListNode nextPair = second.next;

            //swapping algo
            prev.next = second; //after swapping the first element will be the second
            second.next = first;
            first.next = nextPair; //this will connect the swapped pairs with next node

            //shifting prev to the end of swapped pairs
            prev = first;

        }
        
        return dummy.next;
    }
}