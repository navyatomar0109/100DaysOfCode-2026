import java.util.Scanner;

// Node class
class Node {
    int data;
    Node next;

    Node(int data) {
        this.data = data;
        this.next = null;
    }
}

public class Question2 {

    // Function to segregate even and odd nodes
    public static Node segregateEvenOdd(Node head) {

        // If list is empty
        if (head == null) {
            return null;
        }

        // Heads and tails for even and odd lists
        Node evenHead = null, evenTail = null;
        Node oddHead = null, oddTail = null;

        Node current = head;

        // Traverse the original list
        while (current != null) {

            // Save next node before changing links
            Node nextNode = current.next;

            // Break the current node's link
            current.next = null;

            // Check if current node is even
            if (current.data % 2 == 0) {

                // First even node
                if (evenHead == null) {
                    evenHead = current;
                    evenTail = current;
                }
                // Add to end of even list
                else {
                    evenTail.next = current;
                    evenTail = current;
                }
            }
            // Current node is odd
            else {

                // First odd node
                if (oddHead == null) {
                    oddHead = current;
                    oddTail = current;
                }
                // Add to end of odd list
                else {
                    oddTail.next = current;
                    oddTail = current;
                }
            }

            // Move to next node
            current = nextNode;
        }

        // If there are no even nodes
        if (evenHead == null) {
            return oddHead;
        }

        // Join even list with odd list
        evenTail.next = oddHead;

        return evenHead;
    }

    // Function to print linked list
    public static void printList(Node head) {

        Node temp = head;

        while (temp != null) {
            System.out.print(temp.data);

            if (temp.next != null) {
                System.out.print(" -> ");
            }

            temp = temp.next;
        }

        System.out.println();
    }

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        System.out.print("Enter number of nodes: ");
        int n = sc.nextInt();

        Node head = null;
        Node tail = null;

        System.out.println("Enter node values:");

        // Create linked list
        for (int i = 0; i < n; i++) {

            int value = sc.nextInt();

            Node newNode = new Node(value);

            if (head == null) {
                head = newNode;
                tail = newNode;
            } else {
                tail.next = newNode;
                tail = newNode;
            }
        }

        // Rearrange even and odd nodes
        head = segregateEvenOdd(head);

        // Print modified linked list
        System.out.println("Modified Linked List:");
        printList(head);

        sc.close();
    }
}