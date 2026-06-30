
class Solution {
    public ListNode swapPairs(ListNode head) {
        ListNode dummy = new ListNode();
        dummy.next = head;
        ListNode node = dummy;
        while(node != null){
            ListNode first = node.next;
            ListNode sec = null;
            if(first != null){
                sec = first.next;
            }
            if(sec != null){
                ListNode secNext = sec.next;
                sec.next = first;
                node.next = sec;
                first.next = secNext;
                node = first;
            }
            else{
                break;
            }
        }
        return dummy.next;
    }
}