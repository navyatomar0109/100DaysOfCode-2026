class Solution {
    public boolean isPalindrome(ListNode head) {
        int count = 0;
        ListNode temp = head;
        while (temp != null) {
            count++;
            temp = temp.next;
        }
        
        int arr[] = new int[count];
        temp = head;
        for (int i = 0; i < count; i++) {
            arr[i] = temp.val;
            temp = temp.next;
        }
        
        for (int i = 0; i < count / 2; i++) {
            if (arr[i] != arr[count - 1 - i]) {
                return false;
            }
        }
        
        return true;
    }
}
