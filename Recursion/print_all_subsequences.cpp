//print all subsequence
//subsequence-> A contigious and non - contigious sequence which follows the order
// a subarray is just contigious but the a subsequence is contigious or not contigious
/*arr[3]->{3,1,2}
subsequece->3,1,2,(3,1),(1,2),(2,3),(3,1,2),{}  ---->for n=3 we arre having 8 subsequences
see 3,1,2,(3,1),(1,2)are contigious but (2,3) is not contigious but it is a subsequence
A subarray can be a subsequence */
//For every index we are having 2 options wether we take that number or not

#include<bits/stdc++.h>
using namespace std;

void sub(int indx,vector<int>arr,vector<int>&a,int n)
{
    if(indx==n)
    {
        for(int i=0;i<a.size();i++)
        {
            cout<<a[i]<<" ";
        }
        if(a.size()==0)
        cout<<"{}";
        cout<<endl;
        return ;
    }
    a.push_back(arr[indx]);//take or added to our subsequence 
    sub(indx+1,arr,a,n);
    a.pop_back();//not take or not added to our subsequence
    sub(indx+1,arr,a,n);
}


int main()
{
    int n;
    cin>>n;
    vector<int>arr(n);
    vector<int>a(0);
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    sub(0,arr,a,n);

    return 0;
}

//TC->O(2^n)*n
//sc->O(n)