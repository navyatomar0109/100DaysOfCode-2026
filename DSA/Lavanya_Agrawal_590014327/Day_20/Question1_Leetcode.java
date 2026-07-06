import java.util.Scanner;

class ListNode {
    int val;
    ListNode next;

    ListNode(int val) {
        this.val = val;
    }
}

public class Question1_Leetcode {

    static ListNode removeElements(ListNode head, int val) {

        ListNode dummy = new ListNode(0);
        dummy.next = head;

        ListNode current = dummy;

        while (current.next != null) {
            if (current.next.val == val) {
                current.next = current.next.next;
            } else {
                current = current.next;
            }
        }

        return dummy.next;
    }

    static ListNode createList(Scanner sc, int n) {

        if (n == 0)
            return null;

        ListNode head = new ListNode(sc.nextInt());
        ListNode temp = head;

        for (int i = 1; i < n; i++) {
            temp.next = new ListNode(sc.nextInt());
            temp = temp.next;
        }

        return head;
    }

    static void printList(ListNode head) {

        if (head == null) {
            System.out.println("[]");
            return;
        }

        while (head != null) {
            System.out.print(head.val);

            if (head.next != null)
                System.out.print(" ");

            head = head.next;
        }
    }

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();

        ListNode head = createList(sc, n);

        int val = sc.nextInt();

        head = removeElements(head, val);

        printList(head);

        sc.close();
    }
}