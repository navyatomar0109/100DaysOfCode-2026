class Node {
    int val;
    Node next;
    Node(int x) { val = x; }
}

class Question2 {
    public static void main(String args[]) {
        Node head = new Node(1);
        head.next = new Node(2);
        head.next.next = new Node(3);
        head.next.next.next = new Node(4);
        head.next.next.next.next = new Node(5);
        int n = 2;
        
        Node dummy = new Node(0);
        dummy.next = head;
        Node slow = dummy;
        Node fast = dummy;
        
        for (int i = 0; i <= n; i++) {
            fast = fast.next;
        }
        
        while (fast != null) {
            slow = slow.next;
            fast = fast.next;
        }
        
        slow.next = slow.next.next;
        
        Node temp = dummy.next;
        System.out.print("[");
        while (temp != null) {
            System.out.print(temp.val);
            if (temp.next != null) {
                System.out.print(",");
            }
            temp = temp.next;
        }
        System.out.println("]");
    }
}
