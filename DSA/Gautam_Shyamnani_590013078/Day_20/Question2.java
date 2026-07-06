class ListNode{
    int val;
    ListNode next;

    ListNode(int val){
        this.val = val;
        this.next = null;
    }
}

public class Question2 {
    public static ListNode segregateEvenOdd(ListNode head){
        if(head == null || head.next == null) return head;

        ListNode evenHead = null, evenTail = null;
        ListNode oddHead = null, oddTail = null;

        ListNode curr = head;
        
        while(curr != null){
            if(curr.val % 2 == 0){
                if(evenHead == null){
                    evenHead = evenTail = curr;
                }else{
                    evenTail.next = curr;
                    evenTail = curr;
                }
            } else {
                if(oddHead == null){
                    oddHead = oddTail = curr;
                }else{
                    oddTail.next = curr;
                    oddTail = curr;
                }
            }
            curr = curr.next;
        }
        if(evenTail != null) evenTail.next = oddHead;
        if(oddTail != null) oddTail.next = null;

        return (evenHead != null) ? evenHead : oddHead;
    }
    public static void printList(ListNode head){
        ListNode curr = head;
        while(curr != null){
            System.out.print(curr.val);
            if(curr.next != null) System.out.print(" -> ");
            curr = curr.next;
        }
        System.out.println();
    }
    public static void main(String[] args){
        ListNode head = new ListNode(17);
        head.next = new ListNode(15);
        head.next.next = new ListNode(8);
        head.next.next.next = new ListNode(9);
        head.next.next.next.next = new ListNode(2);
        head.next.next.next.next.next = new ListNode(4);
        head.next.next.next.next.next.next = new ListNode(6);

        System.out.println("Original List: ");
        printList(head);

        head = segregateEvenOdd(head);

        System.out.println("Rearranged List: ");
        printList(head);
    }
}
