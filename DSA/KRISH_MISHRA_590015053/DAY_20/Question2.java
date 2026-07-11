import java.util.Scanner;

public class Main {

    static class ListNode {
        int val;
        ListNode next;
        ListNode(int val) { this.val = val; this.next = null; }
    }

    public static ListNode segregateEvenOdd(ListNode head) {
        ListNode evenHead = null, evenTail = null;
        ListNode oddHead = null, oddTail = null;

        ListNode curr = head;

        while (curr != null) {
            if (curr.val % 2 == 0) {
                if (evenHead == null) {
                    evenHead = curr;
                    evenTail = curr;
                } else {
                    evenTail.next = curr;
                    evenTail = curr;
                }
            } else {
                if (oddHead == null) {
                    oddHead = curr;
                    oddTail = curr;
                } else {
                    oddTail.next = curr;
                    oddTail = curr;
                }
            }
            curr = curr.next;
        }

        if (evenTail != null) {
            evenTail.next = oddHead;
        }

        if (oddTail != null) {
            oddTail.next = null;
        }

        return (evenHead != null) ? evenHead : oddHead;
    }

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();

        ListNode head = null, curr = null;
        for (int i = 0; i < n; i++) {
            ListNode node = new ListNode(sc.nextInt());
            if (head == null) {
                head = node;
                curr = head;
            } else {
                curr.next = node;
                curr = curr.next;
            }
        }

        ListNode result = segregateEvenOdd(head);

        while (result != null) {
            System.out.print(result.val + " ");
            result = result.next;
        }
        System.out.println();

        sc.close();
    }
}
