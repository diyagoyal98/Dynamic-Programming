#include<iostream>
#include<vector>
using namespace std;

//Recursion 

/*int fib(int n)
{
    if(n<=1)
    return n;

    return fib(n-1)+fib(n-2);
}
int main()
{
    int n;
    cin>>n;
    cout<<fib(n);
    return 0;
}*/


//Memoization--->Top Down

/*int fib(int n,vector<int>&dp)
{
    if(n<=1)
    dp[n]=n;

    if(dp[n]!=-1)
    return dp[n];

    return dp[n]=fib(n-1,dp)+fib(n-2,dp);
}


int main()
{
    int n;
    cin>>n;
    vector<int>dp(n+1,-1);
    cout<<fib(n,dp);
    return 0;
}*/

//Time comp--> O(n)
//Space comp--> O(n)+O(n) {one for stack space and one for thid dp array}



//Tabulation ---> Bottom Up

/*int fib(int n,vector<int>&dp)
{
    dp[0]=0;
    dp[1]=1;
    int prev,curr;

    for(int i=2;i<=n;i++)
    {
        dp[i]=dp[i-1]+dp[i-2];
    }
    return dp[n];
}

int main()
{
    int n;
    cin>>n;
    vector<int>dp(n+1,-1);
    cout<<fib(n,dp);
    return 0;
}*/


//Time com-->O(n)
//Space Com-->O(n) {Only for dp array}



//Space Optimization 
int fib(int n)
{
    if(n<=1)
    return n;

    int prev=0;
    int curr=1;
    int nxt;
    for(int i=2;i<=n;i++)
    {
        nxt=prev+curr;
        prev=curr;
        curr=nxt;
    }
    return curr;
}
int main()
{
    int n;
    cin>>n;
    
    cout<<fib(n);
    return 0;
}


//TC--> O(N)
//Sp--> O(1) {No extra Space}