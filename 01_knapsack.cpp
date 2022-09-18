#include<bits/stdc++.h>
using namespace std;

/*int knapsack(vector<int>weight,vector<int>value,int wt,int n)
{
    if(n==0 || wt==0)
    return 0;

    if(weight[n-1]>wt)
    return knapsack(weight,value,wt,n-1);
    else if(weight[n-1]<=wt)
    {
        return max(value[n-1]+knapsack(weight,value,wt-weight[n-1],n-1),knapsack(weight,value,wt,n-1));
    }
}*/

/*int knapsack(vector<int>weight,vector<int>value,int wt,int n,vector<vector<int>>&dp)
{
    if(n==0 || wt==0)
    dp[n][wt]=0;

    if(dp[n][wt]!=-1)
    return dp[n][wt];

    if(weight[n-1]>wt)
    return dp[n-1][wt]=knapsack(weight,value,wt,n-1,dp);
    else if(weight[n-1]<=wt)
    {
        return dp[n-1][wt]=max(value[n-1]+knapsack(weight,value,wt-weight[n-1],n-1,dp),knapsack(weight,value,wt,n-1,dp));
    }
}*/

int knapsack(vector<int>weight,vector<int>value,int wt,int n,vector<vector<int>>&dp)
{
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=wt;j++)
        {
            if(i==0 || j==0) 
            dp[i][j]=0;
            else if(weight[i-1]<=wt)
            dp[i][j]=max(value[i-1]+dp[i-1][j-weight[i-1]],dp[i-1][j]);
            else 
            {
                dp[i][j]=dp[i-1][j];
            }
        }
    }

    return dp[n][wt];
}

int main()
{
    int n;
    cin>>n;
    vector<int>weight(n);
    vector<int>value(n);
    for(int i=0;i<n;i++)
    {
        cin>>value[i];
    }
    for(int i=0;i<n;i++)
    {
        cin>>weight[i];
    }
    int wt;
    cin>>wt;
    
    vector<vector<int>>dp(n+1,vector<int>(wt+1,0));
    //cout<<knapsack(weight,value,wt,n);
    cout<<knapsack(weight,value,wt,n,dp)<<endl;

    return 0;
}