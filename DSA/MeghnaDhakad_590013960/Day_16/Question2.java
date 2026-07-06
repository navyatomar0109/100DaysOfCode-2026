package DSA.MeghnaDhakad_590013960.Day_16;

class Node {
    int data;
    Node prev, next;

    Node(int data) {
        this.data = data;
    }
}

public class Question2 {

    public static Node deleteLast(Node head) {

        if (head == null || head.next == null) {
            return null;
        }

        Node curr = head;

        while (curr.next != null) {
            curr = curr.next;
        }

        curr.prev.next = null;

        return head;
    }

    public static void printList(Node head) {

        while (head != null) {
            System.out.print(head.data);

            if (head.next != null) {
                System.out.print(" <-> ");
            }

            head = head.next;
        }

        System.out.println();
    }

    public static void main(String[] args) {

        Node head = new Node(1);

        head.next = new Node(2);
        head.next.prev = head;

        head.next.next = new Node(3);
        head.next.next.prev = head.next;

        head.next.next.next = new Node(4);
        head.next.next.next.prev = head.next.next;

        System.out.print("Original: ");
        printList(head);

        head = deleteLast(head);

        System.out.print("After Deletion: ");
        printList(head);
    }
}
