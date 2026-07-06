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
    // Function to remove the N-th node from the end of a linked list
    public static Node remove_Nth_node(Node head, int n) {
        int length = 0;
        Node current = head;
        // Find the length
        while (current != null) {
            length++;
            current = current.next;
        }
        // If the node to remove is the head
        if (length == n) {
            return head.next;
        }
        // Move to the node just before the one to delete
        current = head;
        for (int i = 1; i < length - n; i++) {
            current = current.next;
        }
        // Delete the node
        current.next = current.next.next;
        return head;
    }
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
        if(n==0){
            System.out.println("Linked list is empty");
            return;
        }
        System.out.println("Enter the values of nodes:");
        Node head=new Node(sc.nextInt());
        Node current=head;
        // Create the linked list by adding nodes
        for(int i=1;i<n;i++){
            current.next=new Node(sc.nextInt());
            current=current.next;         
        }
    System.out.println("Original Linked List:");
    print_LinkedList(head); 
    System.out.println("Enter the position of node to be deleted from end:");
        int pos=sc.nextInt();
        head=remove_Nth_node(head,pos);
        System.out.println("\nLinked List after deleting the node at position "+pos+" from end:");
        print_LinkedList(head);
        sc.close();
}
}