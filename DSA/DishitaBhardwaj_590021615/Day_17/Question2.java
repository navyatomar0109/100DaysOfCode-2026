import java.util.HashSet;

class ListNode {
    int val;
    ListNode next;

    ListNode(int val) {
        this.val = val;
        this.next = null;
    }
}

public class Question2 {

    public boolean hasCycle(ListNode head) {
        if (head == null)
            return false;

        HashSet<ListNode> visited = new HashSet<>();
        ListNode current = head;

        while (current != null) {
            if (visited.contains(current)) {
                return true;
            }
            visited.add(current);
            current = current.next;
        }

        return false;
    }

    public static void main(String[] args) {
        Question2 sol = new Question2();   // Correct class name

        // Create nodes
        ListNode head = new ListNode(3);
        head.next = new ListNode(2);
        head.next.next = new ListNode(0);
        head.next.next.next = new ListNode(-4);

        // Create a cycle
        head.next.next.next.next = head.next;

        System.out.println(sol.hasCycle(head)); // true
    }
}