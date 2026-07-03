public class Question1_Leetcode{
    public ListNode deleteDuplicates(ListNode head) {
        ListNode current=head ; // Initialize current pointer to the head of the list

        // Traverse the list until the end is reached
        while(current!=null && current.next!=null){ 

            // If the current node's value is equal to the next node's value, skip the next node (duplicate node)
            if(current.val==current.next.val) current.next=current.next.next; 

            // Else, move the current pointer to the next node
            else current=current.next; 
        }
        
    return head;  // Return the modified list with duplicates removed 
    }
}