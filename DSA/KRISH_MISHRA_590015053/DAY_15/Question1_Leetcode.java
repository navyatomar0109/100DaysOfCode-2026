import java.util.Scanner;

public class Main {

    static class ListNode {
        int val;
        ListNode next;
        ListNode(int val) { this.val = val; this.next = null; }
    }

    public static ListNode mergeTwoLists(ListNode l1, ListNode l2) {
        if (l1 == null) return l2;
        if (l2 == null) return l1;

        if (l1.val <= l2.val) {
            l1.next = mergeTwoLists(l1.next, l2);
            return l1;
        } else {
            l2.next = mergeTwoLists(l1, l2.next);
            return l2;
        }
    }

    public static ListNode buildList(Scanner sc, int n) {
        if (n == 0) return null;
        ListNode head = new ListNode(sc.nextInt());
        ListNode curr = head;
        for (int i = 1; i < n; i++) {
            curr.next = new ListNode(sc.nextInt());
            curr = curr.next;
        }
        return head;
    }

    public static void printList(ListNode head) {
        while (head != null) {
            System.out.print(head.val + " ");
            head = head.next;
        }
        System.out.println();
    }

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        int n1 = sc.nextInt();
        ListNode l1 = buildList(sc, n1);

        int n2 = sc.nextInt();
        ListNode l2 = buildList(sc, n2);

        ListNode merged = mergeTwoLists(l1, l2);
        printList(merged);

        sc.close();
    }
}
