import java.util.Scanner;

public class Main {

    static class ListNode {
        int val;
        ListNode next;
        ListNode(int val) { this.val = val; this.next = null; }
    }

    public static ListNode rotateRight(ListNode head, int k) {
        if (head == null) return null;
        if (k == 0) return head;

        ListNode cur = head;
        int n = 1;
        while (cur.next != null) {
            cur = cur.next;
            n++;
        }

        cur.next = head;

        int pos = n + (-k) % n;

        ListNode ans = head;
        ListNode prev = null;
        for (int i = 0; i < pos; i++) {
            prev = ans;
            ans = ans.next;
        }

        prev.next = null;
        return ans;
    }

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        int k = sc.nextInt();

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

        ListNode result = rotateRight(head, k);

        while (result != null) {
            System.out.print(result.val + " ");
            result = result.next;
        }
        System.out.println();

        sc.close();
    }
}
