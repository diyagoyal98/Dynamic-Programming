//Print count of the subsequence whode sum equal to k

#include<bits/stdc++.h>
using namespace std;

int sub_one(int indx,int a[],int n,int k,int sum)
{
    if(indx==n)
    {
        if(sum==k)
        {
            return 1;
        }
        return 0;
    }
    sum+=a[indx];
    int l=sub_one(indx+1,a,n,k,sum);

    sum-=a[indx];
    int r=sub_one(indx+1,a,n,k,sum);
    

    return l+r;
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
    int k;
    cin>>k;

    cout<<sub_one(0,arr,n,k,0);
    return 0;
}

//tc->O(2^n)
