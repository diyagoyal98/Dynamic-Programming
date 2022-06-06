//Printing subsequences whose sum is k
#include<bits/stdc++.h>
using namespace std;

void sub_sum(int indx,int a[],int k,int n,int sum,vector<int>ans)
{
    if(indx==n)
    {
        if(sum==k)
        {
            for(int i=0;i<ans.size();i++)
            {
                cout<<ans[i]<<"  ";
            }
            cout<<endl;
        }
        return ;
    }

    ans.push_back(a[indx]);
    sum+=a[indx];
    sub_sum(indx+1,a,k,n,sum,ans);
    ans.pop_back();
    sum-=a[indx];
    sub_sum(indx+1,a,k,n,sum,ans);
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
    sub_sum(0,arr,k,n,0,ans);
    return 0;
}
