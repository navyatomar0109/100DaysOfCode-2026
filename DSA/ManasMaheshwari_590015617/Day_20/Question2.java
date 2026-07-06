class Node {
    int val;
    Node next;
    Node(int x) { val = x; }
}

class Question2 {
    public static void main(String args[]) {
        Node head = new Node(17);
        head.next = new Node(15);
        head.next.next = new Node(8);
        head.next.next.next = new Node(9);
        head.next.next.next.next = new Node(2);
        head.next.next.next.next.next = new Node(4);
        head.next.next.next.next.next.next = new Node(6);
        
        Node evenHead = new Node(0);
        Node oddHead = new Node(0);
        
        Node even = evenHead;
        Node odd = oddHead;
        
        Node current = head;
        
        while (current != null) {
            if (current.val % 2 == 0) {
                even.next = current;
                even = even.next;
            } else {
                odd.next = current;
                odd = odd.next;
            }
            current = current.next;
        }
        
        even.next = oddHead.next;
        odd.next = null;
        
        Node result = evenHead.next;
        if (result == null) {
            result = oddHead.next;
        }
        
        Node temp = result;
        while (temp != null) {
            System.out.print(temp.val);
            if (temp.next != null) {
                System.out.print(" -> ");
            }
            temp = temp.next;
        }
    }
}
