class Node {
    int data;
    Node prev;
    Node next;

    Node(int data) {
        this.data = data;
        prev = null;
        next = null;
    }
}

class Solution {
    public Node deleteLastNode(Node head) {

        // If the list is empty
        if (head == null) {
            return null;
        }

        // If there is only one node
        if (head.next == null) {
            return null;
        }

        // Traverse to the last node
        Node temp = head;
        while (temp.next != null) {
            temp = temp.next;
        }

        // Delete the last node
        temp.prev.next = null;

        return head;
    }
}
