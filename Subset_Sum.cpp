//If their is an subset present in the array whose sum is equal to the given sum
#include<bits/stdc++.h>
using namespace std;

//Recursive
/*bool subset_sum(int n,vector<int>arr,int sum)
{
    if(n==0 && sum==0)
    return true;
    else if(sum==0)
    return true;
    else if(n==0)
    return false;

    if(arr[n-1]>sum)
    return subset_sum(n-1,arr,sum);
    else if(arr[n-1]<=sum)
    return subset_sum(n-1,arr,sum-arr[n-1]) || subset_sum(n-1,arr,sum);

}*/

//Memoized 
/*bool subset_sum(int n,vector<int>arr,int sum,vector<vector<int>>&dp)
{
    if(n==0 && sum==0)
    dp[n][sum]=1;
    else if(sum==0)
    dp[n][sum]=1;
    else if(n==0)
    dp[n][sum]=0;

    if(dp[n][sum]!=-1)
    return dp[n][sum];
    else if(arr[n-1]>sum)
    return dp[n-1][sum]=subset_sum(n-1,arr,sum,dp);
    else if(arr[n-1]<=sum)
    return dp[n-1][sum]= subset_sum(n-1,arr,sum-arr[n-1],dp) || subset_sum(n-1,arr,sum,dp);
}*/

//Tabuation

bool subset_sum(int n,vector<int>arr,int sum,vector<vector<int>>&dp)
{
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=sum;j++)
        {
            if(i==0 && j==0)
            dp[i][j]=1;
            else if(j==0)
            dp[i][j]=1;
            else if(i==0)
            dp[i][j]=0;
        }    
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=sum;j++)
        {
            if(arr[i-1]>j)
            dp[i][j]=dp[i-1][j];
            else if(arr[i-1]<=j)
            dp[i][j]=dp[i-1][j-arr[i-1]] || dp[i-1][j];
        }
        
    }
    return dp[n][sum];
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
    int sum;
    cin>>sum;
    vector<vector<int>>dp(n+1,vector<int>(sum+1,-1));
    cout<<subset_sum(n,arr,sum,dp);
    //cout<<subset_sum(n,arr,sum);
    return 0;

}