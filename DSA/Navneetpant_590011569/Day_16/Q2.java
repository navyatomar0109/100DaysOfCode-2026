class Solution {
    public Node deleteLast(Node head) {

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
        temp.prev = null;

        return head;
    }
}