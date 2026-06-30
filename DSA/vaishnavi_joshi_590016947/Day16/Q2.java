import java.util.Scanner;

class Node {
    int data;
    Node prev;
    Node next;

    Node(int data) {
        this.data = data;
        this.prev = null;
        this.next = null;
    }
}

public class Main {

    // Delete the last node
    public static Node deleteLastNode(Node head) {

        // Case 1: Empty List
        if (head == null) {
            return null;
        }

        // Case 2: Only One Node
        if (head.next == null) {
            return null;
        }

        // Traverse to the last node
        Node current = head;

        while (current.next != null) {
            current = current.next;
        }

        // Delete the last node
        current.prev.next = null;

        return head;
    }

    // Print the Doubly Linked List
    public static void printList(Node head) {

        if (head == null) {
            System.out.println("NULL");
            return;
        }

        Node temp = head;

        while (temp != null) {
            System.out.print(temp.data);

            if (temp.next != null) {
                System.out.print(" <-> ");
            }

            temp = temp.next;
        }

        System.out.println();
    }

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        System.out.print("Enter the number of elements in the linked list: ");
        int n = sc.nextInt();

        if (n == 0) {
            System.out.println("The linked list is empty.");
            return;
        }

        System.out.println("Enter the elements of the linked list:");

        Node head = new Node(sc.nextInt());
        Node tail = head;

        for (int i = 1; i < n; i++) {

            Node newNode = new Node(sc.nextInt());

            tail.next = newNode;
            newNode.prev = tail;

            tail = newNode;
        }

        System.out.print("\nOriginal Doubly Linked List: ");
        printList(head);

        head = deleteLastNode(head);

        System.out.print("After deleting the last node: ");
        printList(head);

        sc.close();
    }
}