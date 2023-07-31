#include<iostream>

using namespace std;

int num[10001];
int main()
{
    int n;
    cin>>n;
    for(int i = 0; i < n; i++)
    {
        cin>>num[i];
    }
    int ans;
    for(int i = 1, j = 1; i <= n; i++)
    {
        if(num[i - 1] + 1 == num[i])
        {
            j++;
        }
        else
        {
            if(j > ans)
            {
                ans = j;
            }
            j = 1;
        }
    }
    cout<<ans;
    return 0;
}
