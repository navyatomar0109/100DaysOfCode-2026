public class Detect_cycle {

    public static class Listnode{
        int val;
        Listnode next;
        Listnode(int val){
            this.val = val;
            this.next = null;
        }
    }

    //method to display linked list
    public static void Display( Listnode head){
        
        Listnode temp = head;
        while(temp != null){
            System.out.print(temp.val + " ");
            temp = temp.next;
        }
        System.out.println();
    }


    //function to detect cycle in a linked list
    public boolean hasCycle(Listnode head) {
        if (head == null) {
            return false;
        }

        Listnode slow = head;
        Listnode fast = head;

        while (fast != null && fast.next != null) {
            slow = slow.next;          // move 1 step
            fast = fast.next.next;     // move 2 steps

            if (slow == fast) {
                return true;
            }
        }

        return false;
    }

    //main class
    public static void main(String[] args){

        Listnode head = new Listnode(1);
        Listnode temp = head;

        for(int i=2; i<=5; i++){
            temp.next = new Listnode(i);
            temp = temp.next;
        }

        System.out.println("Linked list is: ");
        Display(head);
        
        //creating a cycle in the linked list
        temp.next = head.next; // creating a cycle for testing
        
        //detecting cycle in the linked list
        Detect_cycle detectCycle = new Detect_cycle();

        boolean hasCycle = detectCycle.hasCycle(head);
        
        if(hasCycle){
            System.out.println("The linked list has a cycle.");
        } else {
            System.out.println("The linked list does not have a cycle.");
        }
    }

}