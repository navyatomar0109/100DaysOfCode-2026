import java.util.Scanner;

class Node {
    int data;
    Node next;

    Node(int data) {
        this.data = data;
    }
}

public class Question2 {

    static Node segregateEvenOdd(Node head) {

        if (head == null || head.next == null)
            return head;

        Node evenStart = null, evenEnd = null;
        Node oddStart = null, oddEnd = null;

        Node current = head;

        while (current != null) {

            Node next = current.next;
            current.next = null;

            if (current.data % 2 == 0) {

                if (evenStart == null) {
                    evenStart = evenEnd = current;
                } else {
                    if (evenEnd != null) {
                        evenEnd.next = current;
                    }
                    evenEnd = current;
                }

            } else {

                if (oddStart == null) {
                    oddStart = oddEnd = current;
                } else {
                    if (oddEnd != null) {
                        oddEnd.next = current;
                    }
                    oddEnd = current;
                }
            }

            current = next;
        }

        if (evenStart == null)
            return oddStart;

        if (oddStart == null)
            return evenStart;

        if (evenEnd != null) {
            evenEnd.next = oddStart;
            return evenStart;
        }

        return oddStart;
    }

    static Node createList(Scanner sc, int n) {

        if (n == 0)
            return null;

        Node head = new Node(sc.nextInt());
        Node temp = head;

        for (int i = 1; i < n; i++) {
            temp.next = new Node(sc.nextInt());
            temp = temp.next;
        }

        return head;
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

        Node head = createList(sc, n);

        head = segregateEvenOdd(head);

        printList(head);

        sc.close();
    }
}