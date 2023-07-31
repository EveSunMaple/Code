#include<iostream>

using namespace std;

int main()
{
    int m, t, s;
    cin>>m>>t>>s;
    if(t == 0)
        cout<<0;
    else
    {
        int ans = (m * t - s) / t;
        if(ans < 0)
            ans = 0;
        cout<<ans;
    }
    return 0;
}