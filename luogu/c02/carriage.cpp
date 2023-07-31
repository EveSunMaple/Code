#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <queue>
#define N 100005

using namespace std;

struct carriage
{
    int nxt;
    int ver;
}edge[N];

int val[N];
int head[N];
int dist[N];
bool tag[N];
int tot = 0;
int n, m, s;

void add(int u, int v, int w)
{
    val[++tot] = w;
	edge[tot].ver = v;
	edge[tot].nxt = head[u];
	head[u] = tot;
}

priority_queue<pair<int, int>> q;

void init(int s)
{
    memset(dist, 0x3f, sizeof(dist));
    memset(tag, 0, sizeof(tag));
    dist[s] = 0; 
    while (!q.empty()) q.pop();
    q.push(make_pair(0, s));
    while (!q.empty())
    {
        int u = q.top().second; 
        q.pop();
        if(tag[u]) continue;
        tag[u] = true; 
        for (int j = head[u]; j; j = edge[j].nxt)
        {
            int v = edge[j].ver;
            if (dist[u] + val[j] < dist[v])
            {
                 dist[v] = dist[u] + val[j];
                 q.push(make_pair(-dist[v], v)); 
            }
        }
    }
}

void solve()
{
    memset(edge, 0, sizeof(edge));
    int n, m, u, v, k;
	scanf("%d%d%d%d%d", &n, &m, &u, &v, &k);
	for (int i = 1; i <= m; i++)
	{
        int a, b, c, d, e;
	    scanf("%d%d%d%d%d", &a, &b, &c, &d, &e);
        int temp = c * min(d, k);
        if (k > d) temp += e * (k - d);
        add(a, b, temp);
	}
    
	init(u);
    printf("%d\n", dist[v]);
}

int main()
{
    freopen("carriage.in", "r", stdin);
    freopen("carriage.out", "w", stdout);
    int n;
    scanf("%d", &n);
    while (n--) solve();
	return 0;
}
