#include<iostream>

using namespace std;

int main()
{
    int l, m;
    cin>>l>>m;
    int t[101][2];
    t[0][0] = -1; t[0][1] = -1;
    int u, v, ans = l + 1;
    for(int i = 1; i <= m; i++)
    {
        cin>>t[i][0]>>t[i][1];
        u = t[i][0]; v = t[i][1];
        for(int j = 1; j <= i; j++)
        {
        	if(t[i][0] < t[i - j][1] && t[i][1] > t[i - j][1])
        	    u = t[i - j][1] + 1;
        	if(t[i][1] > t[i - j][0] && t[i][0] < t[i - j][0])
        	    v = t[i - j][0] - 1;
        	if(t[i][0] == t[i - j][1])
        	    u = t[i - j][1] + 1;
        	if(t[i][1] == t[i - j][0])
        	    v = t[i - j][0] - 1;
		}
		ans -= v - u + 1;
    }
    cout<<ans;
    return 0;
}
