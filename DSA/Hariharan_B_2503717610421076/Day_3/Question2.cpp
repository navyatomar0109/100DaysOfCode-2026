#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
    int n, i, target, occ=0;
    cout<<"Enter the number of elements : "; //getting total number of elements
    cin>>n;
    cout<<endl;
    
    int arr[n];
    
    for(i=0;i<n;i++) //getting values for an array
    {
                    cout<<"Enter the element "<<i+1<<" : ";
                    cin>>arr[i];
    }
    
    cout<<"\nEnter the target value : "; //getting the target vaue
    cin>>target;
    
    occ = count(arr, arr + n, target);
    
    cout<<"\nTotal number of occurrences of "<<target<<" in the array : "<<occ<<endl; //displaying the total accurrences
    
    return 0;
}
    
