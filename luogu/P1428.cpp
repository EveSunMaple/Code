#include<iostream>

using namespace std;

int a[101];
int ans[101];
int main()
{
    int n = 0;
    cin>>n;
    for(int i = 0; i < n; i++)
    {
        cin>>a[i];
        for(int j = 0; j < i; j++)
        {
            if(a[j] < a[i])
            {
                ans[i]++;
            }
        }
    }
    for(int i = 0; i < n; i++)
    {
        cout<<ans[i]<<' ';
    }
    return 0;
}