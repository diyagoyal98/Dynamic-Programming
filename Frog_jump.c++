#include<bits/stdc++.h>
using namespace std;

//Recursion 
/*int fun(int arr[],int num)
{
    if(num==0)
    return 0;

    int left=fun(arr,num-1)+abs(arr[num]-arr[num-1]);
    int right=INT_MAX;
    if(num>1)
    right=fun(arr,num-2)+abs(arr[num]-arr[num-2]);

    return min(left,right);
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
    int ans=fun(arr,n-1);
    cout<<ans;
}*/

//Memoization

/*int fun(int arr[],int num,vector<int>&dp)
{
    if(num==0)
    return 0;

    if(dp[num]!=-1)
    return dp[num];

    int left=fun(arr,num-1,dp)+abs(arr[num]-arr[num-1]);
    int right=INT_MAX;
    if(num>1)
    right=fun(arr,num-2,dp)+abs(arr[num]-arr[num-2]);

    return dp[num]=min(left,right);
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
    vector<int>dp(n,-1);

    int ans=fun(arr,n-1,dp);
    cout<<ans;
}*/

//Tabulation

/*int fun(int arr[],int num,vector<int>&dp)
{
    if(num==0)
    dp[num]=0;

    for(int i=1;i<=num;i++)
    {
        int left=fun(arr,i-1,dp)+abs(arr[i]-arr[i-1]);
        int right=INT_MAX;
        if(i>1)
        right=fun(arr,i-2,dp)+abs(arr[i]-arr[i-2]);

        dp[i]=min(left,right);
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
    vector<int>dp(n,0);

    int ans=fun(arr,n-1,dp);
    cout<<ans;
}*/


//Space Optimization

int fun(int arr[],int num)
{
    int prev2=0,prev1=0;
    for(int i=1;i<=num;i++)
    {
        int left=prev1+abs(arr[i]-arr[i-1]);
        int right=INT_MAX;
        if(i>1)
        right= prev2+abs(arr[i]-arr[i-2]);

        int curr=min(left,right);
        prev2=prev1;
        prev1=curr;   
    }
    return prev1;
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
    vector<int>dp(n,0);

    int ans=fun(arr,n-1);
    cout<<ans;
}
