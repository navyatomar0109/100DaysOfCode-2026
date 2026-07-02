class Question2{
    public ListNode removen(ListNode head,int n){
        ListNode dummy=new ListNode(0);
        dummy.next=head;
        ListNode f=dummy,s=dummy;
        
        for(int i=0;i<=n;i++){
            f=f.next;
            while(f!=null){
                f=f.next;
                s=s.next;
            }

        }
        s.next=s.next.next;
        return dummy.next;

    }
}