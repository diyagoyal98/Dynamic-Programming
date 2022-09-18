#include<bits/stdc++.h>
using namespace std;

//Recursion
/*int sub_set(int n,vector<int>arr,int target)
{
    if(n==0 && target==0)
    return 1;
    else if(target==0)
    return 1;
    else if(n==0)
    return 0;

    if(arr[n-1]>target)
    return sub_set(n-1,arr,target);
    else if(arr[n-1]<=target)
    return sub_set(n-1,arr,target-arr[n-1]) || sub_set(n-1,arr,target);
}*/

//Memoized

bool sub_set(int n,vector<int>arr,int target,vector<vector<int>>&dp)
{
    if(n==0 && target==0)
    dp[n][target]=1;
    else if(target==0)
    dp[n][target]=1;
    else if(n==0)
    dp[n][target]=0;

    if(dp[n][target]!=-1)
    return dp[n][target];
    else if(arr[n-1]>target)
    return dp[n-1][target]=sub_set(n-1,arr,target,dp);
    else if(arr[n-1]<=target)
    return dp[n-1][target]= sub_set(n-1,arr,target-arr[n-1],dp) || sub_set(n-1,arr,target,dp);
}

int main()
{
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int target=0;
    for(int i=0;i<n;i++)
    {
        target+=arr[i];
    }
    
    if((target%2)!=0)
    {
        cout<<"0";
        exit(0);
    }    
    else
    {
        int t=target/2;
        vector<vector<int>>dp(n+1,vector<int>(t+1,-1));
        cout<<sub_set(n,arr,target,dp);
    }
    return 0;
}