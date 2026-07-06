class Node {
    int data;
    Node prev, next;

    Node(int data) {
        this.data = data;
    }
}

public class Question_2 {

    public static Node deleteLast(Node head) {

        if (head == null) {
            return null;
        }

        if (head.next == null) {
            return null;
        }

        Node temp = head;

        while (temp.next != null) {
            temp = temp.next;
        }

        temp.prev.next = null;

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
    }

    public static void main(String[] args) {

        Node head = new Node(1);
        Node second = new Node(2);
        Node third = new Node(3);
        Node fourth = new Node(4);

        head.next = second;
        second.prev = head;

        second.next = third;
        third.prev = second;

        third.next = fourth;
        fourth.prev = third;

        System.out.print("Original List: ");
        printList(head);

        head = deleteLast(head);

        System.out.print("\nAfter Deletion: ");
        printList(head);
    }
}