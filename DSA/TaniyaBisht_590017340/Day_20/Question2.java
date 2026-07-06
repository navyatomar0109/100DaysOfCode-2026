
class ListNode{
    int val; ListNode next;
    ListNode(int val){
        this.val = val; this.next = null;
    }
}
class SLL{
    public static ListNode segregate(ListNode head){
        ListNode evenHead = null, evenTail = null;
        ListNode oddHead = null, oddTail = null;
        ListNode curr = head;
        while(curr != null){
            if(curr.val % 2 == 0){
                if(evenHead == null){
                    evenHead = curr;
                    evenTail = curr;
                } 
                else{
                    evenTail.next = curr;
                    evenTail = curr;
                }
            }
            else{
                if(oddHead == null){
                    oddHead = curr;
                    oddTail = curr;
                } 
                else{
                    oddTail.next = curr;
                    oddTail = curr;
                }
            }
            curr = curr.next;
        }
        if(evenHead == null){
            oddTail.next = null;
            return oddHead;
        }
        if(oddHead == null){
            evenTail.next = null;
            return evenHead;
        }
        evenTail.next = oddHead;
        oddTail.next = null;
        return evenHead;
    }
    public static void printList(ListNode head){
        while(head != null){
            System.out.print(head.val);
            if(head.next != null){
                System.out.print("->");
            }
            head = head.next;
        }
        System.out.println();
    }
    public static void main(String[] args){
        ListNode n1 = new ListNode(17);
        ListNode n2 = new ListNode(15);
        ListNode n3 = new ListNode(8);
        ListNode n4 = new ListNode(9);
        ListNode n5 = new ListNode(2);
        ListNode n6 = new ListNode(4);
        ListNode n7 = new ListNode(6);
        n1.next = n2;
        n2.next = n3;
        n3.next = n4;
        n4.next = n5;
        n5.next = n6;
        n6.next = n7;
        ListNode head = segregate(n1);
        printList(head);
    }
}