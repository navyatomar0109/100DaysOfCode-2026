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
    public ListNode deleteDuplicates(ListNode head) {
        if (head==null) {
            return head;
        }
        ListNode slow = head;
        ListNode fast = head.next;
        ListNode current = head;
        int count = 0;

        while (current!=null) {
            count++;
            current = current.next;

        }

        for (int i = 0 ; i<count-1 ; i ++ ) {
            if (slow==null){
                return head;
            }
            if (slow.val==fast.val) {
                slow.next=fast.next;
                fast=fast.next;
                
                
            }
            else{
                slow=slow.next;
                fast= fast.next;
            }
        }
        return head;
        

        
    }
}