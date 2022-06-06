//Reverse an array using two pointer

#include<iostream>
using namespace std;

void reverse_arr(int *a,int l,int r)
{
    if(l>=r)
    return ;
    swap(a[l],a[r]);

    reverse_arr(a,l+1,r-1);
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
    reverse_arr(arr,0,n-1);
    cout<<"After reverse.....\n";
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<"    ";
    }
    return 0;
}


