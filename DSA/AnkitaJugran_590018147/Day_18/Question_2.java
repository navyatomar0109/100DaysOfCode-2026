public class Remove_nth_node {

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

    // Remove nth node from the end
    public static ListNode removeNthFromEnd(ListNode head, int n) {

        if (n <= 0) {
            System.out.println("Invalid value of n.");
            return head;
        }

        // Create dummy node
        ListNode dummy = new ListNode(0);
        dummy.next = head;

        ListNode fast = dummy;
        ListNode slow = dummy;

        // Move fast n+1 steps ahead
        for (int i = 0; i <= n; i++) {
            fast = fast.next;
        }

        // Move both pointers
        while (fast != null) {
            fast = fast.next;
            slow = slow.next;
        }

        // Delete the node
        slow.next = slow.next.next;

        return dummy.next;
    }

    public static void main(String[] args) {

        // Create list
        ListNode head = new ListNode(1);
        ListNode temp = head;

        for (int i = 2; i <= 5; i++) {
            temp.next = new ListNode(i);
            temp = temp.next;
        }

        System.out.println("Original Linked List:");
        display(head);

        int n = 2;
        head = removeNthFromEnd(head, n);

        System.out.println("After removing " + n + "th node from end:");
        display(head);
    }
}