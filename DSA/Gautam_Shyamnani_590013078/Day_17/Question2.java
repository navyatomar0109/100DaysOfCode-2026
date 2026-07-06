public class Question2 {
    static class ListNode{
        int val;
        ListNode next;

        ListNode(int val){
            this.val = val;
            this.next = null;
        }
    }
    public static boolean hasCycle(ListNode head){
        ListNode slow = head, fast = head;

        while(fast != null && fast.next != null){
            slow = slow.next;
            fast = fast.next.next;

            if(slow == fast) return true;
        }
        return false;
    }

public static void main(String[] args){
    ListNode head = new ListNode(1);
    head.next = new ListNode(2);
    head.next.next = head;

    System.out.println(hasCycle(head));
    }
}