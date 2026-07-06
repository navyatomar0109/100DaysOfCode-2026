class Node {
    int data;
    Node next;

    Node(int data) {
        this.data = data;
        next = null;
    }
}

class Solution {

    static Node segregateEvenOdd(Node head) {
        if (head == null)
            return null;

        Node evenHead = null, evenTail = null;
        Node oddHead = null, oddTail = null;

        Node curr = head;

        while (curr != null) {
            Node nextNode = curr.next;
            curr.next = null;   // detach current node

            if (curr.data % 2 == 0) {
                if (evenHead == null) {
                    evenHead = evenTail = curr;
                } else {
                    evenTail.next = curr;
                    evenTail = curr;
                }
            } else {
                if (oddHead == null) {
                    oddHead = oddTail = curr;
                } else {
                    oddTail.next = curr;
                    oddTail = curr;
                }
            }

            curr = nextNode;
        }

        // No even nodes
        if (evenHead == null)
            return oddHead;

        // Attach odd list after even list
        evenTail.next = oddHead;

        return evenHead;
    }
}
