public class Question1_Leetcode {
    public ListNode rotateRight(ListNode head, int k) {
        // Check whether the linked list is empty or has only one node, or if k is zero (no rotation needed)
        if(head==null|| head.next==null|| k==0) return head;
        int length =1;
        ListNode lastnode = head;
        // Traverse the linked list to find its length and the last node
        while(lastnode.next!=null){
           lastnode=lastnode.next;
            length++;
        }
        k=k % length; //Number of rotations needed 
        if(k==0) return head; // If k is a multiple of the length, return the original head (no rotation needed)
        lastnode.next=head; //Make the linked list circular by connecting the last node to the head
        ListNode current =head;
        // Traverse the linked list to find the new head after rotation
        for(int i=0;i<length-k-1;i++){
            current=current.next;
        }
        ListNode newhead=current.next; //New head after rotation
        current.next=null; //Break the circular link 
        return newhead;          
    }
}