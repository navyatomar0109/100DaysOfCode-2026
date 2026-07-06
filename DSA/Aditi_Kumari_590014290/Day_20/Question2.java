package Day_20;

class Node {
    int val;
    Node next;

    Node(int val) {
        this.val = val;
    }
}

public class Question2 {

    public Node segregateEvenOdd(Node head) {

        if (head == null || head.next == null)
            return head;

        Node evenHead = null;
        Node evenTail = null;
        Node oddHead = null;
        Node oddTail = null;

        Node current = head;

        while (current != null) {

            Node nextNode = current.next;
            current.next = null;

            if (current.val % 2 == 0) {

                if (evenHead == null) {
                    evenHead = evenTail = current;
                } else {
                    evenTail.next = current;
                    evenTail = current;
                }

            } else {

                if (oddHead == null) {
                    oddHead = oddTail = current;
                } else {
                    oddTail.next = current;
                    oddTail = current;
                }
            }

            current = nextNode;
        }

        if (evenHead == null)
            return oddHead;

        evenTail.next = oddHead;

        return evenHead;
    }
}