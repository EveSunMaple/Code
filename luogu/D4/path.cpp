#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <queue>
#define fastio                   \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0)
#define ll long long
#define N 100005

int head[N * 2];
int edge[N * 2];
int son[N * 2];
int ver[N * 2];
int dist[N];
bool tag[N];
int tot = 0;
int n, m, q;
bool fi;

using namespace std;

priority_queue<int> p;

void add(int u, int v, int w)
{
	edge[++tot] = w;
	ver[tot] = v;
	son[tot] = head[u];
	head[u] = tot;
}

void dfs(int u, int t)
{
    tag[u] = true;
    for (int i = head[u]; i; i = son[i])
	{
		int v = ver[i];
        if (tag[v]) continue;
        tag[v] = true;
        p.push(edge[i]);
        if (v == t) 
        {
            fi = true;
            return;
        }
        dfs(v, t);
    }
}

int main()
{
    freopen("path.in", "r", stdin);
    freopen("path.out", "w", stdout);
    fastio;
    scanf("%d%d%d", &n, &m, &q);
	for (int i = 1; i <= m; i++)
	{
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		add(u, v, w);  add(v, u, w);
	}

    for (int i = 1; i <= q; i++)
    {
        int u, t;
        scanf("%d%d", &u, &t);
        memset(tag, 0, sizeof(tag));
        while (!p.empty()) p.pop();
        fi = false; dfs(u, t);
        int max_num = p.top();
        while (!p.empty() && p.top() == max_num) p.pop();
        if (fi) 
        {
            if (p.empty()) printf("0\n");
            else printf("%d\n", p.top()); 
        }
        else printf("-1\n");
    }

    return 0;
}