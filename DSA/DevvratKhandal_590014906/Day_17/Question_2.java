class Node {
    int data;
    Node next;

    Node(int data) {
        this.data = data;
    }
}

public class Question_2 {

    public static boolean hasCycle(Node head) {

        Node slow = head;
        Node fast = head;

        while (fast != null && fast.next != null) {

            slow = slow.next;
            fast = fast.next.next;

            if (slow == fast)
                return true;
        }

        return false;
    }

    public static void main(String[] args) {

        Node head = new Node(3);
        Node second = new Node(2);
        Node third = new Node(0);
        Node fourth = new Node(-4);

        head.next = second;
        second.next = third;
        third.next = fourth;

        // Create cycle
        fourth.next = second;

        if (hasCycle(head))
            System.out.println("true");
        else
            System.out.println("false");
    }
}