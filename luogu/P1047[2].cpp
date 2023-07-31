#include<iostream>

using namespace std;

int t[10001];
int main()
{
    int l, m;
    cin>>l>>m;
    int u, v, ans = 0;
    for(int i = 0; i <= l; i++)
    {
    	t[i] = 1;
	}
    for(int i = 0; i < m; i++)
    {
        cin>>u>>v;
        for(int j = u; j <= v; j++)
        {
        	t[j]++;
		}
    }
    for(int i = 0; i <= l; i++)
    {
    	if(t[i] == 1)
    	ans++;
	}
    cout<<ans;
    return 0;
}
