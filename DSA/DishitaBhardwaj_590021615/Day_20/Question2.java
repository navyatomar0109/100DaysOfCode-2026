import java.util.*;
class ListNode {
    int val;
    ListNode next;
    ListNode(int val) { this.val = val; }
}
public class Question2 {
    public static ListNode segregateEvenOdd(ListNode head) {
        if (head == null || head.next == null) return head;
        ListNode evenDummy = new ListNode(0);
        ListNode oddDummy = new ListNode(0);
        ListNode evenTail = evenDummy;
        ListNode oddTail = oddDummy;
        ListNode curr = head;
        while (curr != null) {
            if (curr.val % 2 == 0) {
                evenTail.next = curr;
                evenTail = evenTail.next;
            } else {
                oddTail.next = curr;
                oddTail = oddTail.next;
            }
            curr = curr.next;
        }
        evenTail.next = oddDummy.next;
        oddTail.next = null;
        return evenDummy.next;
    }
    public static void printList(ListNode head) {
        ListNode curr = head;
        while (curr != null) {
            System.out.print(curr.val);
            if (curr.next != null) System.out.print(" -> ");
            curr = curr.next;
        }
        System.out.println();
    }
    public static void main(String[] args) {
        ListNode head = new ListNode(17);
        head.next = new ListNode(15);
        head.next.next = new ListNode(8);
        head.next.next.next = new ListNode(9);
        head.next.next.next.next = new ListNode(2);
        head.next.next.next.next.next = new ListNode(4);
        head.next.next.next.next.next.next = new ListNode(6);
        System.out.println("Original List:");
        printList(head);
        head = segregateEvenOdd(head);
        System.out.println("Modified List (Even before Odd):");
        printList(head);
    }
}

