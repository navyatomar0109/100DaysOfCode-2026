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
    static ListNode midNode(ListNode head) 
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

    public static void main(String[] args) 
    {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter number of nodes: ");
        int n = sc.nextInt();
        if (n == 0) 
        {
            System.out.println("List is empty.");
            return;
        }

        System.out.println("Enter node values:");
        ListNode head = new ListNode(sc.nextInt());
        ListNode temp = head;
        for (int i = 1; i < n; i++) 
        {
            temp.next = new ListNode(sc.nextInt());
            temp = temp.next;
        }

        ListNode mid = midNode(head);
        System.out.println("Middle Node: " + mid.val);

        sc.close();
    }
}
