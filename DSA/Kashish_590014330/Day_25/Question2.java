import java.util.Scanner;

class Main {
    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter target:");
        int target = sc.nextInt();
        System.out.println("Enter size:");
        int size = sc.nextInt();
        int[] arr = new int[size];
        System.out.println("Enter array:");
        for (int i = 0; i < arr.length; i++) {
            arr[i] = sc.nextInt();
        }
        
        int left = 0;
        int right = arr.length - 1;
        int sum = 0;
        
        
        boolean found = false; 

        while (left < right) {
            sum = arr[left] + arr[right];
            
            if (sum == target) {
                found = true;
                break; 
            } 
            else if (sum < target) {
                left++;  
            } 
            else {
                right--; 
            }
        }

        
        if (found) {
            System.out.println("true");
        } else {
            System.out.println("false");
        }
    }
}