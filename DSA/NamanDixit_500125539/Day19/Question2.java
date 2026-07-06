
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

// Main class
public class Question2 {

    // Function to find the middle node
    public static Node findMiddle(Node head) {

        // Two pointers
        Node slow = head;
        Node fast = head;

        // Move slow by 1 step and fast by 2 steps
        while (fast != null && fast.next != null) {
            slow = slow.next;
            fast = fast.next.next;
        }

        // Slow will point to the middle node
        return slow;
    }

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        // Enter number of nodes
        System.out.print("Enter number of nodes: ");
        int n = sc.nextInt();

        Node head = null;
        Node tail = null;

        // Create linked list
        System.out.println("Enter node values:");

        for (int i = 0; i < n; i++) {

            int value = sc.nextInt();

            Node newNode = new Node(value);

            // First node
            if (head == null) {
                head = newNode;
                tail = newNode;
            } // Add node at the end
            else {
                tail.next = newNode;
                tail = newNode;
            }
        }

        // Find middle node
        Node middle = findMiddle(head);

        // Print result
        System.out.println("Middle Node: " + middle.data);

        sc.close();
    }
}
