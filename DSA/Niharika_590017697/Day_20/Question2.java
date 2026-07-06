import java.util.Scanner;
class Node 
{
    int data;
    Node next;
    Node(int data) 
    {
        this.data = data;
        this.next = null;
    }
}

public class Question2 
{
    static Node insert(Node head, int data) 
    {
        Node newNode = new Node(data);
        if (head == null)
            return newNode;

        Node temp = head;
        while (temp.next != null) 
            temp = temp.next;

        temp.next = newNode;
        return head;
    }

    static Node seperateEvenOdd(Node head) 
    {
        if (head == null || head.next == null)
            return head;

        Node evenHead = null, evenTail = null;
        Node oddHead = null, oddTail = null;
        Node curr = head;

        while (curr != null) 
        {

            if (curr.data % 2 == 0) 
            {

                if (evenHead == null) 
                {
                    evenHead = curr;
                    evenTail = curr;
                } 
                else 
                {
                    evenTail.next = curr;
                    evenTail = curr;
                }

            } 
            else 
            {
                if (oddHead == null) 
                {
                    oddHead = curr;
                    oddTail = curr;
                } 
                else 
                {
                    oddTail.next = curr;
                    oddTail = curr;
                }
            }
            curr = curr.next;
        }
        if (evenHead == null) 
        {
            oddTail.next = null;
            return oddHead;
        }
        if (oddHead == null) 
        {
            evenTail.next = null;
            return evenHead;
        }
        evenTail.next = oddHead;
        oddTail.next = null;

        return evenHead;
    }

    static void display(Node head) 
    {
        Node temp = head;
        while (temp != null) 
        {
            System.out.print(temp.data);
            if (temp.next != null)
                System.out.print(" -> ");

            temp = temp.next;
        }
        System.out.println();
    }

    public static void main(String[] args) 
    {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter number of nodes: ");
        int n = sc.nextInt();
        Node head = null;

        System.out.println("Enter node values:");
        for (int i = 0; i < n; i++) 
        {
            int value = sc.nextInt();
            head = insert(head, value);
        }

        head = seperateEvenOdd(head);
        System.out.print("Output: ");
        display(head);

        sc.close();
    }
}
