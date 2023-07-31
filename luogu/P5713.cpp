#include<iostream>

using namespace std;

int main()
{
    int n;
    cin>>n;
    if(n * 5 > (n * 3 + 11))
        cout<<"Luogu";
    else
        cout<<"Local";
}