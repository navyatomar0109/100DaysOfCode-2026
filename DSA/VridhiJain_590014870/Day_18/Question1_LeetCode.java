class Solution {
    public ListNode rotateRight(ListNode head, int k) {
        int listLength = 0;
        ListNode temp = head;
        ListNode last = head;
        while(temp != null){
            last = temp;
            temp = temp.next;
            listLength++;
        }
        if(listLength == 0) return head;
        k = k % listLength;
        System.out.print(listLength);
        last.next = head;
        temp = head;
        for(int i = 0; i < listLength - k - 1; i++){
            temp = temp.next;
        }
        ListNode newHead = temp.next;
        temp.next = null;
        return newHead;
    }
}