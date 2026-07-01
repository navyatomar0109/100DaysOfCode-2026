package Day_17;

import java.util.*;
class ListNode {
    int val;
    ListNode next;
    ListNode(int val) {
        this.val = val;
        this.next = null;
    }
}

public class d17question1_leetcode {
    
    public static class Solution {
    public boolean isPalindrome(ListNode h) {
        if (h == null || h.next == null) return true;
        ListNode s = h, f = h;
        while (f.next != null && f.next.next != null) {
            s = s.next;
            f = f.next.next;
        }
        ListNode p = null, c = s.next;
        while (c != null) {
            ListNode n = c.next;
            c.next = p;
            p = c; c = n;
        }
        while (p != null) {
            if (h.val != p.val) return false;
            h = h.next; p = p.next;
        }
        return true;
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
        Boolean palindrome = sol.isPalindrome(list1);
     
        System.out.println(palindrome);
        sc.close();
    }}