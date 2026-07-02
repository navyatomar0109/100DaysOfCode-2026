import java.util.Scanner;

class ListNode {
    int val;
    ListNode next;

    ListNode(int val) {
        this.val = val;
    }
}

public class Question2 {

    static ListNode removeNthFromEnd(ListNode head, int n) {

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

    static ListNode createList(Scanner sc, int size) {

        if (size == 0)
            return null;

        ListNode head = new ListNode(sc.nextInt());
        ListNode temp = head;

        for (int i = 1; i < size; i++) {
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

        int size = sc.nextInt();

        ListNode head = createList(sc, size);

        int n = sc.nextInt();

        head = removeNthFromEnd(head, n);

        printList(head);

        sc.close();
    }
}