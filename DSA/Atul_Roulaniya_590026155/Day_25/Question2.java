import java.util.*;
class targetsum
{
    public static void main(String args[])
    {
        Scanner sc=new Scanner(System.in);
        int size;
        System.out.println("Enter the size of array:");
        size=sc.nextInt();
        int arr[]=new int[size];
        System.out.println("Enter array elements in ascending order");
        for(int i=0 ; i < size ; i++)
        {
            System.out.println("Enter "+(i+1)+" Elements");
            arr[i]=sc.nextInt();
        }
        System.out.println("Enter target element");
        int target=sc.nextInt();
        boolean found=false;
        for(int i=0 ; i < size ; i++)
        {
            for(int j=i ; j < size ; j++)
            {
                if(arr[i]+arr[j]==target)
                {
                    found=true;
                    break;
                }
            }
        }
        if(found)
        {
            System.out.println("True");
        }
        else
        {
            System.out.println("False");
        }
    }
}