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
// Function to detect if a linked list has a cycle using Floyd's Cycle Detection Algorithm
public static boolean hasCycle(Node head) {
        Node slow=head;  
        Node fast=head;
        while(fast!=null && fast.next!=null){
            slow=slow.next;// Move slow pointer by 1 step
            fast=fast.next.next;// Move fast pointer by 2 steps
        
        if(slow==fast) return true;  // If slow and fast pointers meet, there is a cycle
        }
        return false; 
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
        if(n==0){
            System.out.println("Linked list is empty");
            return;
        }
        System.out.println("Enter the values of nodes:");
        Node head=new Node(sc.nextInt());
        Node current=head;
        for(int i=1;i<n;i++){
            current.next=new Node(sc.nextInt());
            current=current.next;         
}
    // Print the linked list Without cycle
    System.out.println("Linked List:");
    print_LinkedList(head);
        System.out.println("Enter the position where last node points to (-1 for no cycle):");
        int pos = sc.nextInt();
        // Cycle creation in the linked list if the position is valid
        if (pos != -1) {
            Node cyclenode = head;
        for (int i = 0; i < pos; i++) {
                cyclenode = cyclenode.next;
        }
            current.next = cyclenode; // Create a cycle in the linked list
        }
        System.out.println("Cycle Present: " + hasCycle(head)); //Check if the linked list has a cycle
        sc.close();
    }
}