//Print only one subsequence whose sum is equal to k
#include<bits/stdc++.h>
using namespace std;

bool sub_one(int indx,int a[],int n,int k,vector<int>ans,int sum)
{
    if(indx==n)
    {
        if(sum==k)
        {
            for(int i=0;i<ans.size();i++)
            {
                cout<<ans[i]<<"   ";
            }
            cout<<endl;
            return true;
        }
        return false;
    }
    ans.push_back(a[indx]);
    sum+=a[indx];
    if(sub_one(indx+1,a,n,k,ans,sum))
    return true;
    ans.pop_back();
    sum-=a[indx];
    if(sub_one(indx+1,a,n,k,ans,sum))
    return true;

    return false;
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
    vector<int>ans;
    sub_one(0,arr,n,k,ans,0);
    return 0;
}

//technique to print only one answer
/* write the function and if in the base case condition is satisfied then return a true if not satisfied return false
if(f()==trure)
return 
that means no further recursion calls 
*/