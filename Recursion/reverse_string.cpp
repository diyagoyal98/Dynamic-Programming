 //reverse a array using recursion and single pointer
#include<iostream>
using namespace std;

void reverse_single_ptr(int *a,int l,int n)
{
    if(l>=(n/2))
    return ;
    swap(a[l],a[n-l-1]);
    reverse_single_ptr(a,l+1,n);
}

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    reverse_single_ptr(arr,0,n);
    cout<<"After reverse....\n";
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<"  ";
    }
    return 0;
}