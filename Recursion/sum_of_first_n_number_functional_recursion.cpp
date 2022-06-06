//sum of fist n numbers (functional recursion)


#include<iostream>
using namespace std;

int sum(int n)
{
    if(n==0)
    return 0;
    return n+sum(n-1);

}

int main()
{
    int n;
    cin>>n;
    cout<<sum(n);
    return 0;
}


//(4,0)->(3,4)->(2,7)->(1,9)->(0,10)->return 

