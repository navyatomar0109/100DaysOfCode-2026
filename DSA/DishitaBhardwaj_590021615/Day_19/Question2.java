import java.util.Scanner;
class ListNode
{
    int val;
    ListNode next;
    ListNode(int val)
    {
        this.val = val;
        this.next = null;
    }
}
public class Question2
{
    public static ListNode middleNode(ListNode head)
    {
        ListNode slow = head;
        ListNode fast = head;
        while (fast != null && fast.next != null)
        {
            slow = slow.next;
            fast = fast.next.next;
        }

        return slow;
    }
    public static void printList(ListNode head)
    {
        while (head != null) {
            System.out.print(head.val);
            if (head.next != null)
                System.out.print(" -> ");
            head = head.next;
        }
        System.out.println();
    }

    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter number of nodes: ");
        int n = sc.nextInt();
        if (n == 0)
        {
            System.out.println("Linked List is empty.");
            return;
        }
        System.out.println("Enter the elements:");
        ListNode head = new ListNode(sc.nextInt());
        ListNode temp = head;
        for (int i = 1; i < n; i++)
        {
            temp.next = new ListNode(sc.nextInt());
            temp = temp.next;
        }
        ListNode middle = middleNode(head);
        System.out.print("Middle node onwards: ");
        printList(middle);
        sc.close();
    }
}