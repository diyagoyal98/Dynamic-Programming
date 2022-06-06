//Check if a string is palindrome or not???

#include<iostream>
using namespace std;
bool pal(string s,int l,int n)
{
    if(l>=n/2)
    return true;

    if(s[l]!=s[n-l-1])
    return false;
    return pal(s,l+1,n);

}

int main()
{
    string s;
    cin>>s;

    if(pal(s,0,s.length())==1)
    cout<<"YES string is palindrome\n";
    else
    cout<<"NO string is not palindrome\n";
    return 0;
}

//tc->O(n/2)
//sp->O(n/2)(auxiliary stack space)