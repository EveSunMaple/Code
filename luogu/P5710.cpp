#include<iostream>

using namespace std;

int main()
{
    int s;
    cin>>s;
    bool a, b;
    if(s % 2 == 0)
        a = true;
    if(s > 4 && s <= 12)
        b = true;
    if(a == true && b == true)
        cout<<1<<" ";
    else
        cout<<0<<" ";
    if(a == true || b == true)
        cout<<1<<" ";
    else
        cout<<0<<" ";
    if((a == true && b == false) || (a == false && b == true))
        cout<<1<<" ";
    else
        cout<<0<<" ";
    if(a == false && b == false)
        cout<<1;
    else
        cout<<0;
    return 0;
}