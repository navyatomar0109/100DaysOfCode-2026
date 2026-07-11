import java.util.Scanner;

public class Main {

    static class Node {
        int val;
        Node next;
        Node back;
        Node(int val) { this.val = val; this.next = null; this.back = null; }
    }

    public static Node deleteTail(Node head) {
        if (head == null || head.next == null) {
            return null;
        }

        Node secondLast = head;
        while (secondLast.next.next != null) {
            secondLast = secondLast.next;
        }

        secondLast.next = null;
        return head;
    }

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();

        Node head = null, curr = null, prev = null;
        for (int i = 0; i < n; i++) {
            Node node = new Node(sc.nextInt());
            if (head == null) {
                head = node;
                curr = head;
            } else {
                curr.next = node;
                node.back = curr;
                curr = curr.next;
            }
        }

        head = deleteTail(head);

        Node temp = head;
        while (temp != null) {
            System.out.print(temp.val + " ");
            temp = temp.next;
        }
        System.out.println();

        sc.close();
    }
}
