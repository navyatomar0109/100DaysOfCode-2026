package Day_16;

import java.util.*;
class ListNode {
    int val;
    ListNode next;
    ListNode(int val) {
        this.val = val;
        this.next = null;
    }
}

public class d16question1_leetcode {
    
    public static class Solution {
    public ListNode swapPairs(ListNode head) {
        ListNode copy = new ListNode(0);
        copy.next = head;

        ListNode prev = copy;

        while (prev.next != null && prev.next.next != null) {

            ListNode first = prev.next;
            ListNode second = first.next;

            // Swap
            first.next = second.next;
            second.next = first;
            prev.next = second;

            // Move to the next pair
            prev = first;
        }

        return copy.next;
    }
}
    public static void main(String[] args) {
                Scanner sc = new Scanner(System.in);

        System.out.print("Enter size of first list: ");
        int n1 = sc.nextInt();
        System.out.println("Enter elements of first list (sorted):");
        ListNode list1 = null, tail1 = null;
        for (int i = 0; i < n1; i++) {
            ListNode node = new ListNode(sc.nextInt());
            if (list1 == null) {
                list1 = node;
                tail1 = node;
            } else {
                tail1.next = node;
                tail1 = node;
            }
        }

        Solution sol = new Solution();
        ListNode split = sol.swapPairs(list1);
        System.out.println("Swap List:");
        while (split != null) {
            System.out.print(split.val + " ");
            split = split.next;
        }
        System.out.println();
    }}