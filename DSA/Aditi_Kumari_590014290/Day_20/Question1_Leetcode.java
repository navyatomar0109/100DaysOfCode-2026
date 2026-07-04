class Question1_Leetcode {
    int val;
    Question1_Leetcode next;
    Question1_Leetcode() {}
    Question1_Leetcode(int val) { this.val = val; }
    Question1_Leetcode(int val, Question1_Leetcode next) { this.val = val; this.next = next; }
}
class Solution {
    public Question1_Leetcode removeElements(Question1_Leetcode head, int val) {
        Question1_Leetcode dummy = new Question1_Leetcode(0);
        dummy.next = head;
        Question1_Leetcode current = dummy;

        while (current.next != null) {
            if (current.next.val == val) {
                current.next = current.next.next;
            } else {
                current = current.next;
            }
        }
        return dummy.next;
    }
}