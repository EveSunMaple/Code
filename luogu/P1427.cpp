#include<iostream>

using namespace std;

int a[101];
int main()
{
    int sum = 0;
    for(int i = 0; i < 101; i++)
    {
        cin>>a[i];
        if(a[i] == 0)
        {
            break;
        }
        sum++;
    }
    for(int i = sum - 1; i >= 0; i--)
    {
        cout<<a[i]<<' ';
    }
    return 0;
}
