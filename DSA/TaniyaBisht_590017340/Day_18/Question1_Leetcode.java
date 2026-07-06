
class Solution {
    public ListNode rotateRight(ListNode head, int k) {
        if(head==null || head.next==null || k==0)
        return head;
        int length=1;
        ListNode tail= head;
        while(tail.next != null){
            tail = tail.next;
            length+=1;
        }
        tail.next = head;
        k = k%length;
        int newTailInd = length-k;
        ListNode newTail=head;
        for(int i=1; i<newTailInd; i++){
            newTail = newTail.next;
        }
        ListNode newHead= newTail.next;
        newTail.next= null;
        return newHead;
    }
}