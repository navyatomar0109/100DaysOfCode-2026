import java.util.Scanner;

public class Main {

    static class ListNode {
        int val;
        ListNode next;
        ListNode(int val) { this.val = val; this.next = null; }
    }

    public static ListNode middleNode(ListNode head) {
        ListNode slow = head;
        ListNode fast = head;

        while (fast != null && fast.next != null) {
            slow = slow.next;
            fast = fast.next.next;
        }

        return slow;
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

        ListNode mid = middleNode(head);

        while (mid != null) {
            System.out.print(mid.val + " ");
            mid = mid.next;
        }
        System.out.println();

        sc.close();
    }
}
