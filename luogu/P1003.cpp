#include<iostream>

using namespace std;

int d[10001][4];
int main()
{
    int n;
    cin>>n;
    for(int i = 0; i < n; i++)
    {
        cin>>d[i][0]>>d[i][1]>>d[i][2]>>d[i][3];
    }
    int x, y;
    cin>>x>>y;
    int ans = -1;
    for(int i = 1; i <= n; i++)
    {
        if(x >= d[n - i][0] && x <= d[n - i][0] + d[n - i][3] && y >= d[n - i][1] && y <= d[n - i][1] + d[n - i][3])
            ans = n - i + 1;
        if(ans > 0)
       		break;
    }
    cout<<ans;
    return 0;
}