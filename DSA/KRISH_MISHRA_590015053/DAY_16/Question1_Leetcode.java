import java.util.Scanner;

public class Main {

    static class ListNode {
        int val;
        ListNode next;
        ListNode(int val) { this.val = val; this.next = null; }
    }

    public static ListNode swapPairs(ListNode head) {
        ListNode dummy = new ListNode(0);
        dummy.next = head;
        ListNode prev = dummy;
        ListNode cur = head;

        while (cur != null && cur.next != null) {
            ListNode npn = cur.next.next;
            ListNode second = cur.next;

            second.next = cur;
            cur.next = npn;
            prev.next = second;

            prev = cur;
            cur = npn;
        }

        return dummy.next;
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

        ListNode result = swapPairs(head);

        while (result != null) {
            System.out.print(result.val + " ");
            result = result.next;
        }
        System.out.println();

        sc.close();
    }
}
