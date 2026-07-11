import java.util.*;

public class Main {

    static class ListNode {
        int val;
        ListNode next;
        ListNode(int val) { this.val = val; this.next = null; }
    }

    public static ListNode reverseList(ListNode head) {
        Stack<Integer> st = new Stack<>();
        ListNode temp = head;

        while (temp != null) {
            st.push(temp.val);
            temp = temp.next;
        }

        ListNode ele = head;
        while (ele != null) {
            ele.val = st.pop();
            ele = ele.next;
        }

        return head;
    }

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        if (n == 0) {
            System.out.println();
            return;
        }

        ListNode head = new ListNode(sc.nextInt());
        ListNode curr = head;
        for (int i = 1; i < n; i++) {
            curr.next = new ListNode(sc.nextInt());
            curr = curr.next;
        }

        ListNode reversed = reverseList(head);

        while (reversed != null) {
            System.out.print(reversed.val + " ");
            reversed = reversed.next;
        }
        System.out.println();

        sc.close();
    }
}
