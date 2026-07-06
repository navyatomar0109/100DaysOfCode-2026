import java.util.Scanner;
class Node 
{
    int data;
    Node prev,next;
    Node(int data) 
    {
        this.data = data;
    }
}

public class Question2 
{
    static Node deleteLast(Node head) 
    {
        if (head == null)
            return null;

        if (head.next == null)
            return null;

        Node temp = head;
        while (temp.next != null) 
            temp = temp.next;

        temp.prev.next = null;

        return head;
    }

    static Node insert(Node head, int data) 
    {
        Node newNode = new Node(data);
        if (head == null)
            return newNode;

        Node temp = head;
        while (temp.next != null) 
        {
            temp = temp.next;
        }

        temp.next = newNode;
        newNode.prev = temp;

        return head;
    }

    static void display(Node head) 
    {
        if (head == null) 
        {
            System.out.println("NULL");
            return;
        }

        Node temp = head;
        while (temp != null) 
        {
            System.out.print(temp.data);
            if (temp.next != null)
                System.out.print(" <-> ");
            temp = temp.next;
        }
        System.out.println();
    }

    public static void main(String[] args) 
    {

        Scanner sc = new Scanner(System.in);
        System.out.println("Enter number of nodes: ");
        int n = sc.nextInt();
        Node head = null;

        System.out.println("Enter list elements: ");
        for (int i = 0; i < n; i++) 
        {
            int data = sc.nextInt();
            head = insert(head, data);
        }

        head = deleteLast(head);
        System.out.println("Output");
        display(head);

        sc.close();
    }
}