#include<bits/stdc++.h>
using namespace std;


//Recusrion 
/*int fun(int num,int arr[],int k)
{
    if(num==0)
    return 0;
    int  mini=INT_MAX;

    
    for(int i=1;i<=k;i++)
    {
        if(num-i>=0)
        {
            int jump_energy=fun(num-i,arr,k) +(abs(arr[num])-abs(arr[num-i]));
            mini=min(mini,jump_energy);
        }    
    }

    return mini;
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
    int ans=fun(n-1,arr,k);
    cout<<ans;

    return 0;
}*/


//Memoization

/*int fun(int num,int arr[],int k,vector<int>&dp)
{
    if(num==0)
    return 0;

    if(dp[num]!=-1)
    return dp[num];
    
    int mini=INT_MAX;
    for(int i=1;i<=k;i++)
    {
        if(num-i>=0)
        {
            int jump_energy=fun(num-i,arr,k,dp)+abs(arr[num]-arr[num-1]);
            mini=min(mini,jump_energy);
        }    
    }
    return dp[num]=mini;
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
    vector<int>dp(n,-1);
    int ans=fun(n-1,arr,k,dp);
    cout<<ans;
    return 0;
}*/


//Tabulation
int fun(int num,int arr[],int k,vector<int>&dp)
{
    if(dp[num==0])
    dp[num]=0;

    int mini=INT_MAX;

    for(int i=1;i<=num;i++)
    {
        for(int j=1;j<=k;j++)
        {
            
            if(i-j>=0)
            {
                int jump_energy=fun(i-j,arr,k,dp)+abs(arr[i]-arr[i-j]);
                mini=min(mini,jump_energy);
            }
        }
        dp[i]=mini;
    }
    return dp[num];
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
    vector<int>dp(n,-1);
    int ans=fun(n-1,arr,k,dp);
    cout<<ans;

    return 0;
}


//We can do space optimiztion from  O(N) to O(K)
//But in the worst case when k is equal to N the space comp will be again same O(N)

