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

    // Function to segregate even and odd nodes
    public static Node segregateEvenOdd(Node head) {

        if (head == null)
            return null;

        Node evenHead = null, evenTail = null;
        Node oddHead = null, oddTail = null;

        Node current = head;

        while (current != null) {

            if (current.data % 2 == 0) { // Even node
                if (evenHead == null) {
                    evenHead = evenTail = current;
                } else {
                    evenTail.next = current;
                    evenTail = current;
                }
            } else { // Odd node
                if (oddHead == null) {
                    oddHead = oddTail = current;
                } else {
                    oddTail.next = current;
                    oddTail = current;
                }
            }

            current = current.next;
        }

        // If there are no even numbers
        if (evenHead == null) {
            oddTail.next = null;
            return oddHead;
        }

        // If there are no odd numbers
        if (oddHead == null) {
            evenTail.next = null;
            return evenHead;
        }

        // Join even and odd lists
        evenTail.next = oddHead;
        oddTail.next = null;

        return evenHead;
    }

    // Display linked list
    public static void display(Node head) {

        System.out.print("Rearranged Linked List: ");

        while (head != null) {
            System.out.print(head.data);

            if (head.next != null)
                System.out.print(" -> ");

            head = head.next;
        }

        System.out.println();
    }

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        System.out.print("Enter number of nodes: ");
        int n = sc.nextInt();

        Node head = null, tail = null;

        System.out.println("Enter the node values:");

        for (int i = 0; i < n; i++) {
            int value = sc.nextInt();

            Node newNode = new Node(value);

            if (head == null) {
                head = tail = newNode;
            } else {
                tail.next = newNode;
                tail = newNode;
            }
        }

        head = segregateEvenOdd(head);

        display(head);

        sc.close();
    }
}