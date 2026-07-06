public class DeleteNodeDLL {

    //Node class for doubly linked list
    public static class Node {
        Node prev;
        int data;
        Node next;

        Node(int data) {
            
            this.prev = null;
            this.data = data;
            this.next = null;
        }
    }

    //method to create a doubly linked list
    public static Node CreateDLL( int val){

        Node head = new Node(val);
        Node current = head;

        for( int i=1 ; i<5; i++){
            Node temp = new Node(val+i);
            current.next = temp;
            temp.prev = current;
            current = current.next;
        }
        return head;
    }

    //method to display doubly linked list
    public static void Display(Node head){
        Node temp = head;
        while(temp != null){
            System.out.print(temp.data + " ");
            temp = temp.next;
        }
        System.out.println();
    }

    //main method to delete last node from doubly linked list
    public static void main(String[] args){

        //calling method to create doubly linked list
        Node head = CreateDLL(1);
        System.out.println("Original doubly linked list is: ");

        //calling method to display doubly linked list
        Display(head);

        //deleting last node from doubly linked list
        Node temp = head;
        while(temp.next != null){
            temp = temp.next;
        }
        temp.prev.next = null;

        System.out.println("Doubly linked list after deleting last node is: ");

        Display(head);
    
    }
}