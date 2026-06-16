#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
    int val, n, i, max=0;
    cout<<"Enter the number of elements : ";
    cin>>n;
    
    int arr[n];
    
    for(i=0;i<n;i++)
    {
                    cout<<i+1<<" : ";
                    cin>>arr[i];
    }
    
    
    
    max = max_element(arr,arr+n);
    
    
    cout<<"Largest element in the array : "<<max;
    system("pause");
   
    return 0;
    
}
