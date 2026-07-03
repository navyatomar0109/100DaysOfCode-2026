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

    // Function to find the middle node of a linked list
    public static Node Middle_Node(Node head){
        Node slow=head; // Initialize slow pointer to the head of the list
        Node fast=head;// Initialize fast pointer to the head of the list

        // Traverse the list with two pointers, slow moves one step and fast moves two steps
        while(fast!=null && fast.next!=null){
            slow=slow.next;
            fast=fast.next.next;
        }
        return slow; // Return the slow pointer, which will be at the middle node when fast reaches the end
    }

    // Function to print the linked list
    public static void print_LinkedList(Node head){
        
        // Traverse the list and print each node's value
        while(head!=null){
            System.out.print(head.value);
            head=head.next;
            // Print " -> " if there are more nodes to print
            if(head!=null){
                System.out.print(" -> ");
            }
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
    Node middleNode=Middle_Node(head); // Call the function Middle_Node to find the middle node
    System.out.println("Middle Node of Linked List is: "+middleNode.value); // Print the value of the middle node
    sc.close();
}
}