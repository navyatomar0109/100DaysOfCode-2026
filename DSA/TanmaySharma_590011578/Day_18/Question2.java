package DSA.TanmaySharma_590011578.Day_18;

import java.util.Scanner;

class ListNode {
    int val;
    ListNode next;

    ListNode(int val) {
        this.val = val;
    }
}

public class Question2 {

    public static ListNode removeNthFromEnd(ListNode head, int n) {

        ListNode dummy = new ListNode(0);
        dummy.next = head;

        ListNode fast = dummy;
        ListNode slow = dummy;

        for (int i = 0; i <= n; i++) {
            fast = fast.next;
        }

        while (fast != null) {
            fast = fast.next;
            slow = slow.next;
        }

        slow.next = slow.next.next;

        return dummy.next;
    }

    public static void printList(ListNode head) {
        System.out.print("[");
        while (head != null) {
            System.out.print(head.val);
            if (head.next != null)
                System.out.print(", ");
            head = head.next;
        }
        System.out.println("]");
    }

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        System.out.print("Enter number of nodes: ");
        int size = sc.nextInt();

        if (size == 0) {
            System.out.println("[]");
            return;
        }

        System.out.println("Enter node values:");

        ListNode head = new ListNode(sc.nextInt());
        ListNode curr = head;

        for (int i = 1; i < size; i++) {
            curr.next = new ListNode(sc.nextInt());
            curr = curr.next;
        }

        System.out.print("Enter n: ");
        int n = sc.nextInt();

        head = removeNthFromEnd(head, n);

        System.out.print("Updated Linked List: ");
        printList(head);

        sc.close();
    }
}
