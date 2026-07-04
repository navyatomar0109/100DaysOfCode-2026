class Solution {
    Node divide(Node head) {
        Node evenHead = null, evenTail = null;
        Node oddHead = null, oddTail = null;

        Node current = head;

        while (current != null) {
            Node nextNode = current.next;
            current.next = null;

            if (current.data % 2 == 0) {
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

        if (evenHead == null) {
            return oddHead;
        }

        evenTail.next = oddHead;

        return evenHead;
    }
}
