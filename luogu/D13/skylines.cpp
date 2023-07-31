#include <iostream>
#include <cstring>
#include <cstdio>
#include <queue>
#define N 200005

using namespace std;

struct skylines
{
    int val;
    int ver;
    int nxt;
}edge[N * 2];
bool tag[N];
int head[N], tot;
int c[N], dist[N];

void init(int s)
{
    memset(dist, 0x3f, sizeof(dist));
    memset(tag, 0, sizeof(tag));
    dist[s] = 0; 
    queue<int> q;
    q.push(s);
    while (!q.empty())
    {
        int u = q.front(); 
        q.pop();
        if(tag[u]) continue;
        tag[u] = true; 
        for (int j = head[u]; j; j = edge[j].nxt)
        {
            int v = edge[j].ver;
            if (dist[u] + edge[j].val < dist[v])
            {
                 dist[v] = dist[u] + edge[j].val;
                 q.push(v); 
            }
        }
    }
}

int main()
{
	freopen("skylines.in", "r", stdin);
	freopen("skylines.out", "w", stdout);
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &c[i]);
    for (int i = 1; i < n; i++)
    {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        edge[++tot].ver = v;
        edge[tot].val = w;
        edge[tot].nxt = head[u];
        head[u] = tot;
        edge[++tot].ver = u;
        edge[tot].val = w;
        edge[tot].nxt = head[v];
        head[v] = tot;
    }
    int q;
    scanf("%d", &q);
    while (q--)
    {
        int u, ans = 1e9; 
		scanf("%d", &u);
        init(u);
        for (int i = 1; i <= n; i++)
        {
            if (i == u) continue;
            ans = min(ans, dist[i] + c[u] - c[i]);
        }
        printf("%d\n", ans);
    }
    return 0;
}
