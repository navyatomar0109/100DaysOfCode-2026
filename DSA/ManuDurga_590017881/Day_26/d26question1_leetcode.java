package Day_26;

import java.util.*;
public class d26question1_leetcode {
    

    public static void sortColors(int[] nums) {
        List<Integer> cpy = new LinkedList<>();
        int count2= 0;
        for(int i=0;i<nums.length;i++){
            if(nums[i]==0){cpy.addFirst(nums[i]);}
            else if(nums[i]==1){cpy.add(nums[i]);}
            else if(nums[i]==2){count2++;}
        }
        for(int i=0;i<count2;i++){
            cpy.add(2);

        }
        
        for (int i=0;i<nums.length;i++) {
        nums[i] = cpy.get(i);
}}

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();          // size of the input array
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = sc.nextInt();     // elements of the array
        }
        sortColors(a);       
        System.out.println(Arrays.toString(a));
        sc.close();
    }
}
