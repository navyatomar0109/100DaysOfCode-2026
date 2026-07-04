public class Middle_element {
    
    static class ListNode {
        int val;
        ListNode next;

        ListNode(int val) {
            this.val = val;
            this.next = null;
        }
    }

    // Display the linked list
    public static void display(ListNode head) {

        if (head == null) {
            System.out.println("List is empty.");
            return;
        }

        ListNode temp = head;

        while (temp != null) {
            System.out.print(temp.val);

            if (temp.next != null) {
                System.out.print(" -> ");
            }

            temp = temp.next;
        }
        System.out.println();
    }

    // Find the middle element of the linked list
    public static ListNode findMiddle( ListNode head ){

        if ( head == null ){
            return null;
        }

        ListNode slow = head;
        ListNode fast = head;

        while ( fast != null && fast.next != null ){
            slow = slow.next;
            fast = fast.next.next;
        }

        return slow;

    }

    public static void main(String[] args){

        ListNode head = new ListNode(1);
        ListNode temp = head;

        for(int i=2; i<=5; i++){
            temp.next = new ListNode(i);
            temp = temp.next;
        }

        System.out.println("Linked list is: ");
        display(head);
        System.out.println("Middle element is: " + findMiddle(head).val);
    }
}
