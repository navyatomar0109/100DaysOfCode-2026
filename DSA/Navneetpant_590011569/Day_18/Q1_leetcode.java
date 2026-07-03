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
        ListNode current = head;
        int size = 0 ;
        ArrayList <Integer> al = new ArrayList <> () ;
        while (current!=null){
            size++;
            current=current.next;

        }
        if (size == 0 ){
            return head;
        }
        k = k % size;
        if (k == 0) return head; // no rotation needed

        size = size - k;
        current = head;
        for (int i = 1 ; i < size ; i ++ ) {
            current = current.next;

        }
        ListNode temp = current;
        current=current.next;

        while (current!=null) {
            al.add(current.val);
            current = current.next;
        }

        current = temp;
        current.next=null;
        
        ListNode temper = new ListNode ();
        ListNode head2 = temper;
        
        for (int i = 0 ; i<al.size(); i++ ) {
            temper.next = new ListNode (al.get(i));
            temper = temper.next;

        }
        temper.next = head;
        head = head2;
        return head2.next;
        
    }
}