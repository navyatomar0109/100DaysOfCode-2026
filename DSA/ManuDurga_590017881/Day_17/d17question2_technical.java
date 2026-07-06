package Day_17;
import java.util.*;

class Node {
    int val;
    Node next;

    Node(int val) {
        this.val = val;
        this.next = null;
    }
}

public class d17question2_technical {

    public static class Solution {
        public boolean hasCycle(Node head) {
            if (head == null) return false;
            Node slow = head;
            Node fast = head;
            while (fast != null && fast.next != null) {
                slow = slow.next;
                fast = fast.next.next;
                if (slow == fast) {
                    return true;
                }
            }
            return false;
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter size of list: ");
        int n = sc.nextInt();
        System.out.println("Enter elements of list:");
        Node head = null, tail = null;
        for (int i = 0; i < n; i++) {
            Node node = new Node(sc.nextInt());
            if (head == null) {
                head = node;
                tail = node;
            } else {
                tail.next = node;
                tail = node;
            }
        }

        System.out.print("Enter pos (index to link tail, -1 for no cycle): ");
        int pos = sc.nextInt();
        if (pos != -1) {
            Node cycleNode = head;
            for (int i = 0; i < pos; i++) {
                cycleNode = cycleNode.next;
            }
            tail.next = cycleNode;
        }

        Solution sol = new Solution();
        System.out.println(sol.hasCycle(head));
        sc.close();
    }
}