class Node {
    int data;
    Node next;

    Node(int data) {
        this.data = data;
        this.next = null;
    }
}

class LinkedList {
    Node head;

    // Add a node at the end (used to build the initial list)
    void insert(int data) {
        Node newNode = new Node(data);
        if (head == null) {
            head = newNode;
            return;
        }
        Node temp = head;
        while (temp.next != null) {
            temp = temp.next;
        }
        temp.next = newNode;
    }

    // Core logic: segregate even-valued nodes before odd-valued nodes
    void segregateEvenOdd() {
        Node evenStart = null, evenEnd = null;
        Node oddStart = null, oddEnd = null;
        Node curr = head;

        while (curr != null) {
            Node nextNode = curr.next; // save next before we relink curr
            curr.next = null;          // detach curr from old chain

            if (curr.data % 2 == 0) {
                if (evenStart == null) {
                    evenStart = curr;
                    evenEnd = curr;
                } else {
                    evenEnd.next = curr;
                    evenEnd = curr;
                }
            } else {
                if (oddStart == null) {
                    oddStart = curr;
                    oddEnd = curr;
                } else {
                    oddEnd.next = curr;
                    oddEnd = curr;
                }
            }
            curr = nextNode;
        }

        // Handle case with no even nodes
        if (evenStart == null) {
            head = oddStart;
            return;
        }

        // Join even chain to odd chain
        evenEnd.next = oddStart;
        head = evenStart;
    }

    void printList() {
        Node temp = head;
        StringBuilder sb = new StringBuilder();
        while (temp != null) {
            sb.append(temp.data);
            if (temp.next != null) sb.append(" -> ");
            temp = temp.next;
        }
        System.out.println(sb.toString());
    }
}

public class Main {
    public static void main(String[] args) {
        LinkedList list = new LinkedList();
        int[] values = {17, 15, 8, 9, 2, 4, 6};
        for (int v : values) list.insert(v);

        System.out.print("Original: ");
        list.printList();

        list.segregateEvenOdd();

        System.out.print("Segregated: ");
        list.printList();
    }
}
