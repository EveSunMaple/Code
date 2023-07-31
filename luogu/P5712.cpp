#include<iostream>

using namespace std;

int main()
{
    int n;
    cin>>n;
    if(n < 0){return 0;}
    cout<<"Today, I ate ";
    cout<<n;
    cout<<" apple";
    if(n > 1)
        cout<<"s";
    cout<<".";
}