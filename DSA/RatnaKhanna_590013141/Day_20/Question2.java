import java.util.Scanner;
class Node {
    int data;
    Node next;
    Node(int data) {
        this.data = data;
        this.next = null;
    }
}
public class Main {
    static Node segregateEvenOdd(Node head) {
        if (head == null || head.next == null)
            return head;
        Node evenHead = null, evenTail = null;
        Node oddHead = null, oddTail = null;
        Node curr = head;
        while (curr != null) {
            Node nextNode = curr.next;
            curr.next = null;
            if (curr.data % 2 == 0) {
                if (evenHead == null) {
                    evenHead = evenTail = curr;
                } else {
                    evenTail.next = curr;
                    evenTail = curr;
                }
            } else {
                if (oddHead == null) {
                    oddHead = oddTail = curr;
                } else {
                    oddTail.next = curr;
                    oddTail = curr;
                }
            }
            curr = nextNode;
        }
        if (evenHead == null)
            return oddHead;
        evenTail.next = oddHead;
        return evenHead;
    }
    static void printList(Node head) {
        while (head != null) {
            System.out.print(head.data);

            if (head.next != null)
                System.out.print(" -> ");

            head = head.next;
        }
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        if (n == 0) {
            return;
        }
        Node head = new Node(sc.nextInt());
        Node tail = head;
        for (int i = 1; i < n; i++) {
            tail.next = new Node(sc.nextInt());
            tail = tail.next;
        }
        head = segregateEvenOdd(head);
        printList(head);

        sc.close();
    }
}
