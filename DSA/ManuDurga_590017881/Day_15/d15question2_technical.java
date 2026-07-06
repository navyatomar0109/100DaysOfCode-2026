package Day_15;
import java.util.*;
public class d15question2_technical {
    public static void main(String[] args) {
        LinkedList<Integer> ll = new LinkedList<>();

        Scanner sc = new Scanner(System.in);

        System.out.println("Enter the elements of the list: ");
        for(int i =0; i<6; i++){
            ll.add(sc.nextInt());
        }

        Collections.reverse(ll);

        System.out.println("Reversed list: " + ll);

     }
    }
