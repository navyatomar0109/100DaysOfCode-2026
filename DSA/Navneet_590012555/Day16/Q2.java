class Node {
    int data;
    Node prev, next;

    Node(int data) {
        this.data = data;
    }
}

Node deleteLast(Node head) {
    if (head == null || head.next == null)
        return null;

    Node t = head;

    while (t.next != null)
        t = t.next;

    t.prev.next = null;

    return head;
}