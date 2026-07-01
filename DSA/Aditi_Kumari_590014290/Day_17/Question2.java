package Day_17;

class Node {
    int val;
    Node next;

    Node() {}

    Node(int val) {
        this.val = val;
    }

    Node(int val, Node next) {
        this.val = val;
        this.next = next;
    }
}
public class Question2 {
    public boolean DetectCycle(Node head){
        Node slow=head;
        Node fast= head;

        while(fast != null && fast.next !=null){
            slow=slow.next;
            fast=fast.next.next;

            if(slow == fast){
                return true;
            }
        }
        return false;
    }
    
}
