#include<bits/stdc++.h>
using namespace std;

/*int fun(int n,vector<int>&arr)
{
    if(n==0)
    return arr[n];
    if(n<0)
    return 0;

    int pick=fun(n-2,arr)+arr[n];
    int nonpick=fun(n-1,arr)+0;

    return max(pick,nonpick);

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

    int ans=fun(n-1,arr);
    cout<<ans;

    return 0;
}*/


//Memoization

/*int fun(int num,vector<int>&arr,vector<int>&dp)
{
    if(num==0)
    dp[num]=arr[num];

    if(num<0)
    dp[num]=0;

    if(dp[num]!=-1)
    return dp[num];

    int pick=arr[num]+fun(num-2,arr,dp);
    int nonpick=0+fun(num-1,arr,dp);

    return dp[num]=max(pick,nonpick);

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
    vector<int>dp(n,-1); 

    int ans=fun(n-1,arr,dp);
    cout<<ans;

    return 0;
}*/



//Tabulation

/*int fun(int num,vector<int>&arr,vector<int>&dp)
{

    dp[0]=arr[0];
    
    for(int i=1;i<=num;i++)
    {
        int pick=arr[i];
        if(i>1)
        pick+=dp[i-2];
        int nonpick=dp[i-1]+0;
        dp[i]=max(pick,nonpick);
    }
    return dp[num];
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
    vector<int>dp(n,0);
    int ans=fun(n-1,arr,dp);
    cout<<ans;

    return 0;
}*/


//Space Optimisation
int fun(int num,vector<int>&arr)
{
    int prev=arr[0];
    int prev2=0;
    int curr;
    for(int i=1;i<=num;i++)
    {
        int pick=arr[i];
        if(i>1)
        pick+=prev2;
        int nonpic=0+prev;

        curr=max(pick,nonpic);
        prev2=prev;
        prev=curr;
    }
    return prev;
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

    int ans=fun(n-1,arr);
    cout<<ans;

    return 0;
}
