
class Solution{
    public ListNode removeElements(ListNode head, int val){
        ListNode dummy = new ListNode(0);
        dummy.next= head;
        ListNode pre = dummy, curr = head;
        while(curr != null){
            if(curr.val == val){
                pre.next = curr.next;
            } 
            else{
                pre = curr;
            }
            curr = curr.next;
        }
        return dummy.next;
    }
}