//Multiple recursion calls(Fibooo)

#include<iostream>
using namespace std;

int fiboo(int n)
{
    if(n<=1)
    return n;
    return fiboo(n-1)+fiboo(n-2);
}




int main()
{
    int n;
    cin>>n;
    cout<<fiboo(n);
    return 0;
} 

//Tc->near O(2^n)
