import java.util.*;
// Create a Node class to represent each node in the linked list
class Node{
        int value;
        Node next;
        Node(int value){
            this.value = value;
            this.next = null;
    }
}
public class Question2{
    // Function to segregate even and odd nodes in a linked list
    public static Node segregateNodes(Node head){

        // Check if the linked list is empty or has only one node
        if( head==null || head.next==null ) return head;

        Node evenStart=null; // Head of the even nodes list
        Node evenEnd=null; // Tail of the even nodes list
        Node oddStart=null; // Head of the odd nodes list
        Node oddEnd=null; // Tail of the odd nodes list
        Node current =head; // Initialize current pointer to the head of the list

        // Traverse the linked list and segregate even and odd nodes

        while(current!=null){
            Node nextnode=current.next; // Store the next node before modifying the current node's next pointer
            current.next=null;          // Disconnect the current node from the list to avoid cycles

        // Check if the current node's value is even or odd and add it to the respective list
            if(current.value % 2 == 0){
                if(evenStart==null){
                evenStart=current;
                evenEnd=current;
            }
            else{
                evenEnd.next=current;
                evenEnd=current;
            }
        }   
        // If the current node's value is odd, add it to the odd nodes list
            else{
            if(oddStart==null){
                oddStart=current;
                oddEnd=current;
            }
            else{
                oddEnd.next=current;
                oddEnd=current;
            }
        }
         current=nextnode; // Move to the next node in the original list
    }
    // If there are no even nodes, return the odd nodes list
         if(evenStart==null){
            return oddStart;
         }
    // Connect the even list with the odd list
            evenEnd.next=oddStart;
    // Return the head of the modified linked list 
            return evenStart;  
}

    // Function to print the linked list

    public static void print_LinkedList(Node head){
        while(head!=null){
            System.out.print(head.value);
            if(head.next!=null){
                System.out.print(" -> ");
            }
            head=head.next;
        }
        System.out.println(" -> NULL");
    }
    public static void main (String args[]){
        Scanner sc=new Scanner(System.in);
        System.out.println("Enter the number of nodes in linked list:");
        int n=sc.nextInt();

        // Check if the linked list is empty
        if(n <= 0){
            System.out.println("Linked list is empty");
            sc.close();
            return;
        }

        System.out.println("Enter the values of nodes:");
        Node head=new Node(sc.nextInt());
        Node current=head; // Initialize current pointer to the head of the list

        // Create the linked list by adding nodes
        for(int i=1;i<n;i++){
            current.next=new Node(sc.nextInt());
            current=current.next;         
        }
    System.out.println("Original Linked List:");
    print_LinkedList(head); // Print the original linked list

    Node newHead=segregateNodes(head); // Segregate even and odd nodes
    System.out.println("\nLinked List after segregating even and odd nodes:");
    print_LinkedList(newHead); // Print the modified linked list

    sc.close();
}
}