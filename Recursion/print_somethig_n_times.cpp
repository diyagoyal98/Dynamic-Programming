//print name n times using recursion 

#include<iostream>
using namespace std;

void fun(int n)
{
    if(n==0)
    return;
    cout<<"Diya..\n";
    fun(n-1);
}

int main()
{
    int n;
    cin>>n;
    fun(n);
    return 0;
}


//tc ->O(n)
//stack complexity->O(n)
