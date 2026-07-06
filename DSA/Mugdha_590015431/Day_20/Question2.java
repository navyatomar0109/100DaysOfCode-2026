package DSA.Mugdha_590015431.Day_20;
import java.util.*;

class ListNode {
    int val;
    ListNode next;

    ListNode(int val) {
        this.val = val;
    }
}

public class Question2 {

    public static ListNode segregateEvenOdd(ListNode head) {

        if (head == null || head.next == null)
            return head;

        ListNode evenHead = null, evenTail = null;
        ListNode oddHead = null, oddTail = null;

        ListNode current = head;

        while (current != null) {

            ListNode nextNode = current.next;
            current.next = null;

            if (current.val % 2 == 0) {

                if (evenHead == null) {
                    evenHead = evenTail = current;
                } else {
                    evenTail.next = current;
                    evenTail = current;
                }

            } else {

                if (oddHead == null) {
                    oddHead = oddTail = current;
                } else {
                    oddTail.next = current;
                    oddTail = current;
                }
            }

            current = nextNode;
        }

        if (evenHead == null)
            return oddHead;

        evenTail.next = oddHead;

        return evenHead;
    }

    public static void printList(ListNode head) {

        while (head != null) {
            System.out.print(head.val);
            if (head.next != null)
                System.out.print(" ");
            head = head.next;
        }
    }

    public static void main(String args[]) {

        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();

        ListNode head = null;
        ListNode tail = null;

        for (int i = 0; i < n; i++) {

            int x = sc.nextInt();

            ListNode node = new ListNode(x);

            if (head == null) {
                head = node;
                tail = node;
            } else {
                tail.next = node;
                tail = node;
            }
        }

        head = segregateEvenOdd(head);

        printList(head);

        sc.close();
    }
}