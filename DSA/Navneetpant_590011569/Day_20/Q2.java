class ListNode {
    int val;
    ListNode next;

    ListNode (int val) {
        this.val = val;
        this.next = null;
    }

}
class Solution {
    public static ListNode oddEven(ListNode head) {
        ListNode even = new ListNode (0);
        ListNode odd = new ListNode (0) ;
        ListNode current = head;
        ListNode result_odd = odd;
        ListNode result_even =even;

        while (current!=null) {
            if (current.val%2==0) {
                even.next = current;
                even = even.next;
                
            }
            else {
                odd.next = current;
                odd = odd.next;
            }
            current = current.next;
        }
        odd.next = null;
        even.next = result_odd.next;
        
        return result_even.next;

    }
}

public class Q2 {
    public static void main(String[] args) {
        int [] arr = {17,15,8,9,2,4,6};

        ListNode head = new ListNode(arr[0]);
        ListNode current = head;
        for (int i = 1; i<arr.length; i++) {
            current.next = new ListNode (arr[i]);
            current = current.next;
        }

        ListNode result = Solution.oddEven(head);
        
        while (result!=null) {
            System.out.print( result.val + " ");
            result = result.next;
        }

    }
}