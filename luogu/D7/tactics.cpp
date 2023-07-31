#include <iostream>
#include <cstring>
#include <cstdio>
#include <queue>
#define fastio                   \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0)
#define ll long long
#define N 105

using namespace std;

int map[N][N];
int dist[N];
bool tag[N];
int ans;

bool SPFA(int s, int k)
{
	memset(dist, 0, sizeof(dist));
	memset(tag, 0, sizeof(tag));
	dist[s] = 0;
	queue<int> q; 
	q.push(s); 
	tag[s] = true;
    int cnt = 0;
	while (!q.empty())
	{
        cnt++;
        if (cnt > k * k) 
        { ans = -1; return false; }
		int u = q.front(); 
		q.pop(); 
		tag[u] = false; 
		for (int v = 1; v <= k; v++)
		{
			if (dist[u] + map[u][v] > dist[v])
			{
				dist[v] = dist[u] + map[u][v];
                ans = max(ans, dist[v]);
				if (!tag[v])
				{
					q.push(v);
					tag[v] = true; 
				}
			}
		}
	}
    return true;
}

void solve()
{
    int k;
    ans = 0;
    scanf("%d", &k);
    for (int i = 1; i <= k; i++)
        for (int j = 1; j <= k; j++)
        {
            scanf("%d", &map[i][j]);
        }
    // for (int i = 1; i <= k; i++)
    // {
    //     for (int j = 1; j <= k; j++)
    //     {
    //         for (int t = 1; t <= k; t++)
    //         {
    //             DP[i][j] = max(DP[i][j], DP[i][t] + DP[t][j]);
    //             ans = max(ans, DP[i][j]);
    //         }
    //     }
    // }
    // for (int i = 1; i <= k; i++)
    // {
    //     for (int j = 1; j <= k; j++)
    //     {
    //         for (int t = 1; t <= k; t++)
    //         {
    //             DP[i][j] = max(DP[i][j], DP[i][t] + DP[t][j]);
    //             if (ans < DP[i][j]) { 
    //             printf("cmp(%d -> DP[%d][%d]<%d>)\n", ans, i, j, DP[i][j]);printf("-1\n"); return; }
    //         }
    //     }
    // }
    for (int i = 1; SPFA(i, k) && i <= k; i++);
    printf("%d\n", ans);
}

int main()
{
    fastio;
    freopen("tactics.in", "r", stdin);
    freopen("tactics.out", "w", stdout);
    int t;
    scanf("%d", &t);
    while (t--) solve();
    return 0;
}
