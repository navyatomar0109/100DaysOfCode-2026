package Day_16;
import java.util.*;
class Node {
    int val;
    Node next;
    Node prev;

    Node(int val) {
        this.val = val;
        this.next = null;
        this.prev = null;
    }
}

public class d16question2_technical {

    public static Node deleteLast(Node head) {
        if (head == null) return null;

        if (head.next == null) return null;

        Node temp = head;
        while (temp.next != null) {
            temp = temp.next;
        }

        Node prevNode = temp.prev;
        prevNode.next = null;  

        return head;
    }

    public static void printList(Node head) {
        Node temp = head;
        while (temp != null) {
            System.out.print(temp.val + " ");
            temp = temp.next;
        }
        System.out.println();
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter size of doubly linked list: ");
        int n = sc.nextInt();

        Node head = null, tail = null;

        System.out.println("Enter " + n + " elements:");
        for (int i = 0; i < n; i++) {
            Node node = new Node(sc.nextInt());
            if (head == null) {
                head = node;
                tail = node;
            } else {
                tail.next = node;
                node.prev = tail;
                tail = node;
            }
        }

        head = deleteLast(head);

        if (head == null) {
            System.out.println("NULL");
        } else {
            Node temp = head;
            while (temp != null) {
                System.out.print(temp.val + " ");
                temp = temp.next;
            }
            System.out.println();
        }

        sc.close();
    }
}


