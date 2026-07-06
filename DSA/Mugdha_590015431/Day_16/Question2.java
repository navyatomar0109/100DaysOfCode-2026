package DSA.Mugdha_590015431.Day_16;
import java.util.*;

class Node {
    int data;
    Node prev, next;

    Node(int data) {
        this.data = data;
    }
}

public class Question2 {

    public static Node deleteLastNode(Node head) {

        if (head == null)
            return null;

        if (head.next == null)
            return null;

        Node temp = head;

        while (temp.next != null) {
            temp = temp.next;
        }

        temp.prev.next = null;

        return head;
    }

    public static void printList(Node head) {
        if (head == null) {
            System.out.println("NULL");
            return;
        }

        while (head != null) {
            System.out.print(head.data);
            if (head.next != null)
                System.out.print(" <-> ");
            head = head.next;
        }
    }

    public static void main(String args[]) {

        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();

        Node head = null;
        Node tail = null;

        for (int i = 0; i < n; i++) {
            int x = sc.nextInt();

            Node newNode = new Node(x);

            if (head == null) {
                head = newNode;
                tail = newNode;
            } else {
                tail.next = newNode;
                newNode.prev = tail;
                tail = newNode;
            }
        }

        head = deleteLastNode(head);

        printList(head);

        sc.close();
    }
}