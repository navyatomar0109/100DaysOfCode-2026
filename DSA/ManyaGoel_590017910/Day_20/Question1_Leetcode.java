public class Question1_Leetcode {
    // function to remove all elements from a linked list of integers that matches the given value "val"
    public ListNode removeElements(ListNode head, int val){

        //Remove all the nodes from the beginning of the list that have the value "val"
        while(head!=null && head.val==val) head=head.next; 

        ListNode current=head; // Initialize current pointer to the head of the list

        //Traverse the list and remove nodes that have the value "val" apart from the beginning of the list
        while(current!=null && current.next!=null){
            if(current.next.val==val) current.next=current.next.next; // Skip the node with value "val" by linking the current node to the next of next node
            else current=current.next; // Move to the next node if the current node's next node does not have the value "val"
        }
    return head;// Return the modified head of the linked list
    }
}