import java.util.Scanner;
class Node {
    int data;
    Node next;
    Node(int data) {
        this.data = data;
        this.next = null;
    }
}
public class Question2 {
    static Node removeNth(Node head, int n) {
        int count = 0;
        Node temp = head;
        while (temp != null) {
            count++;
            temp = temp.next;
        }
        if (n == count) {
            return head.next;
        }
        temp = head;
        for (int i = 1; i < count - n; i++) {
            temp = temp.next;
        }
        temp.next = temp.next.next;
        return head;
    }
    static void printList(Node head) {
        while (head != null) {
            System.out.print(head.data);
            if (head.next != null) {
                System.out.print(" -> ");
            }
            head = head.next;
        }
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter number of nodes: ");
        int size = sc.nextInt();
        Node head = null;
        Node tail = null;
        System.out.println("Enter node values:");
        for (int i = 0; i < size; i++) {
            int value = sc.nextInt();
            Node newNode = new Node(value)
            if (head == null) {
                head = newNode;
                tail = newNode;
            } else {
                tail.next = newNode;
                tail = newNode;
            }
        }
        System.out.print("Enter n: ");
        int n = sc.nextInt();
        head = removeNth(head, n);
        System.out.println("Updated Linked List:");
        printList(head);
        sc.close();
    }
}