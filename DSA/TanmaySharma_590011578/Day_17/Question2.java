package DSA.TanmaySharma_590011578.Day_17;

import java.util.Scanner;

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
        if (head == null || head.next == null) {
            return false;
        }

        ListNode slow = head;
        ListNode fast = head;

        while (fast != null && fast.next != null) {
            slow = slow.next;
            fast = fast.next.next;

            if (slow == fast) {
                return true;
            }
        }

        return false;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        Question2 sol = new Question2();

        System.out.print("Enter number of nodes: ");
        int n = sc.nextInt();

        if (n == 0) {
            System.out.println(false);
            return;
        }

        System.out.print("Enter node values: ");
        ListNode head = new ListNode(sc.nextInt());
        ListNode curr = head;

        // store nodes in array to create cycle later
        ListNode[] nodes = new ListNode[n];
        nodes[0] = head;

        for (int i = 1; i < n; i++) {
            nodes[i] = new ListNode(sc.nextInt());
            curr.next = nodes[i];
            curr = curr.next;
        }

        System.out.print("Enter pos (-1 for no cycle): ");
        int pos = sc.nextInt();

        if (pos != -1) {
            curr.next = nodes[pos]; // create cycle
        }

        System.out.println("Cycle detected: " + sol.hasCycle(head));

        sc.close();
    }
}