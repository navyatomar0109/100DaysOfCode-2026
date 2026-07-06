public class Question1_Leetcode {
    // Function to check if a linked list is a palindrome
    public boolean isPalindrome(ListNode head) {
        ListNode slow = head, fast = head;
        // Find the middle of the linked list using slow and fast pointers
        while (fast != null && fast.next != null) {
            slow = slow.next; // Move slow pointer by 1 step
            fast = fast.next.next;// Move fast pointer by 2 steps
        }
        ListNode prev = null;
        // Reverse the second half of the linked list
        while (slow != null) {
            ListNode next = slow.next;
            slow.next = prev;
            prev = slow;
            slow = next;
        }
        // Compare the first half and the reversed second half of the linked list
        ListNode first_half = head, second_half = prev;
        while (second_half != null) {
            if (first_half.val != second_half.val) return false;
            first_half = first_half.next;
            second_half = second_half.next;
        }
        return true;
    }   
}