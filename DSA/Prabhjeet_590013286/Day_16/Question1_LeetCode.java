//Need to swap every two adjacent nodes in the linked list

class Solution {

    public ListNode swapPairs(ListNode head) {

        ListNode dummy = new ListNode(0);
        dummy.next = head;

        ListNode prev = dummy;

        while (prev.next != null && prev.next.next != null) {

            ListNode first = prev.next;
            ListNode second = first.next;

            // swapping the current pair
            first.next = second.next;
            second.next = first;
            prev.next = second;

            // move to the next pair
            prev = first;
        }

        return dummy.next;
    }
}