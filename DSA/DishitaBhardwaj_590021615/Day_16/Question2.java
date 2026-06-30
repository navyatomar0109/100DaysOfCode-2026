class Node {
    int data;
    Node prev, next;

    Node(int data) {
        this.data = data;
        prev = next = null;
    }
}

public class Question2 {

    // Delete the last node
    static Node deleteLastNode(Node head) {
        if (head == null || head.next == null) {
            return null;
        }

        Node temp = head;

        while (temp.next != null) {
            temp = temp.next;
        }

        temp.prev.next = null;
        temp.prev = null;

        return head;
    }

    // Print the list
    static void printList(Node head) {
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

        // Create the list: 1 <-> 2 <-> 3 <-> 4
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

        head = deleteLastNode(head);

        System.out.print("After Deletion: ");
        printList(head);
    }
}