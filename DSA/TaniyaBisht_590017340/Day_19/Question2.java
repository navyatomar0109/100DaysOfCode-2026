
class ListNode{
    int val; ListNode next;
    ListNode(int val){
        this.val = val; this.next = null;
    }
}
class MLL{
    public static ListNode middleNode(ListNode head){
        ListNode slow = head;
        ListNode fast = head;
        while(fast != null && fast.next != null){
            slow = slow.next;
            fast = fast.next.next;
        }
        return slow;
    }
    public static void main(String[] args){
        ListNode n1 = new ListNode(0);
        ListNode n2 = new ListNode(9);
        ListNode n3 = new ListNode(8);
        ListNode n4 = new ListNode(7);
        ListNode n5 = new ListNode(6);
        ListNode n6 = new ListNode(1);
        n1.next = n2;
        n2.next = n3;
        n3.next = n4;
        n4.next = n5;
        n5.next = n6;
        ListNode middle = middleNode(n1);
        System.out.println("Middle node is:" + middle.val);
    }
}