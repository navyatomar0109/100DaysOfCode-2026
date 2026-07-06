import java.util.*;

class ListNode {
    int val;
    ListNode next;

    ListNode(int val) {
        this.val = val;
    }
}

public class Question2 {

    public static ListNode createList(int[] arr, int pos) {
        if (arr.length == 0) return null;

        ListNode head = new ListNode(arr[0]);
        ListNode temp = head;
        ListNode cycleNode = null;

        if (pos == 0) cycleNode = head;

        for (int i = 1; i < arr.length; i++) {
            temp.next = new ListNode(arr[i]);
            temp = temp.next;

            if (i == pos) {
                cycleNode = temp;
            }
        }

        if (cycleNode != null) {
            temp.next = cycleNode;
        }

        return head;
    }

    public static boolean hasCycle(ListNode head) {
        ListNode slow = head;
        ListNode fast = head;

        while (fast != null && fast.next != null) {
            slow = slow.next;
            fast = fast.next.next;

            if (slow == fast) return true;
        }

        return false;
    }

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        // Input size
        int n = sc.nextInt();

        int[] arr = new int[n];

        // Input elements
        for (int i = 0; i < n; i++) {
            arr[i] = sc.nextInt();
        }

        // Input pos for cycle
        int pos = sc.nextInt();

        ListNode head = createList(arr, pos);

        System.out.println(hasCycle(head));
    }
}