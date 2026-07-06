import java.util.*;

class Node {
    int data;
    Node next;

    Node(int data) {
        this.data = data;
        this.next = null;
    }
}

public class Main {

    // Function to detect cycle
    public static boolean hasCycle(Node head) {

        Node slow = head;
        Node fast = head;

        while (fast != null && fast.next != null) {

            slow = slow.next;          // Move one step
            fast = fast.next.next;     // Move two steps

            if (slow == fast) {
                return true;
            }
        }

        return false;
    }

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        // Number of nodes
        int n = sc.nextInt();

        // First node
        Node head = new Node(sc.nextInt());
        Node temp = head;

        // Store all nodes in an array
        Node[] nodes = new Node[n];
        nodes[0] = head;

        // Create remaining nodes
        for (int i = 1; i < n; i++) {
            Node newNode = new Node(sc.nextInt());
            temp.next = newNode;
            temp = newNode;
            nodes[i] = newNode;
        }

        // Position where last node points
        int pos = sc.nextInt();

        // Create cycle if pos != -1
        if (pos != -1) {
            temp.next = nodes[pos];
        }

        // Print result
        System.out.println(hasCycle(head));

        sc.close();
    }
}