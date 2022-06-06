//subset sum

#include<bits/stdc++.h>
using namespace std;

void subset_sum(int indx,int arr[],int n,vector<int>&ans,int sum)
{
    if(indx==n)
    {
        ans.push_back(sum);
        return;
    }
    sum+=arr[indx];
    subset_sum(indx+1,arr,n,ans,sum);
    sum-=arr[indx];
    subset_sum(indx+1,arr,n,ans,sum);

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
    vector<int>ans;
    subset_sum(0,arr,n,ans,0);
    sort(ans.begin(),ans.end());
    for(int i=0;i<ans.size();i++)
    cout<<ans[i]<<"   ";
    return 0;
}