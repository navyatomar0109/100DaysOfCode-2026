class Solution {
    Node divide(Node head) {

        if (head == null)
            return null;

        Node evenHead = null, evenTail = null;
        Node oddHead = null, oddTail = null;

        Node current = head;

        while (current != null) {

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

            current = current.next;
        }

        if (evenHead == null)
            return oddHead;

        evenTail.next = oddHead;

        if (oddTail != null)
            oddTail.next = null;

        return evenHead;
    }
}