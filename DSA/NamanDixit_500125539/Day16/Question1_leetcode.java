class Question1_leetcode {
    public ListNode swapPairs(ListNode head) {

        if (head == null || head.next == null)
            return head;

        ListNode prev = null;
        ListNode first = head;
        ListNode second = head.next;

        while (first != null && second != null) {

            ListNode third = second.next;

            // Swap the pair
            second.next = first;
            first.next = third;

            // Connect with previous pair
            if (prev != null) {
                prev.next = second;
            } else {
                head = second;
            }

            // Move pointers for next pair
            prev = first;
            first = third;

            if (third != null)
                second = third.next;
        }

        return head;
    }
}