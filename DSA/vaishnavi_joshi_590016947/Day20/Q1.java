import java.util.Scanner;

class ListNode {
    int data;
    ListNode next;

    ListNode(int data) {
        this.data = data;
        this.next = null;
    }
}

public class Main {

    // Function to remove all nodes with the given value
    public static ListNode removeElements(ListNode head, int val) {
        // Remove matching nodes from the beginning
        while (head != null && head.data == val) {
            head = head.next;
        }

        ListNode current = head;

        while (current != null && current.next != null) {
            if (current.next.data == val) {
                current.next = current.next.next;
            } else {
                current = current.next;
            }
        }

        return head;
    }

    // Function to display the linked list
    public static void display(ListNode head) {
        if (head == null) {
            System.out.println("Linked List is empty.");
            return;
        }

        System.out.print("Updated Linked List: ");
        while (head != null) {
            System.out.print(head.data);
            if (head.next != null)
                System.out.print(" -> ");
            head = head.next;
        }
        System.out.println();
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter number of nodes: ");
        int n = sc.nextInt();

        ListNode head = null, tail = null;

        System.out.println("Enter the elements of the linked list:");

        for (int i = 0; i < n; i++) {
            int value = sc.nextInt();
            ListNode newNode = new ListNode(value);

            if (head == null) {
                head = tail = newNode;
            } else {
                tail.next = newNode;
                tail = newNode;
            }
        }

        System.out.print("Enter the value to remove: ");
        int val = sc.nextInt();

        head = removeElements(head, val);

        display(head);

        sc.close();
    }
}