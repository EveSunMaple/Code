#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <queue>
#define N 100005
int head[N * 2];
int edge[N * 2];
int son[N * 2];
int ver[N * 2];
int dist[N];
bool tag[N];
int tot = 0;
int n, m, k;

using namespace std;

void add(int u, int v, int w)
{
	edge[++tot] = w;
	ver[tot] = v;
	son[tot] = head[u];
	head[u] = tot;
}

void SPFA(int k)
{
	memset(dist, 0x3f, sizeof(dist));
	dist[k] = 0;
	queue<int> q; 
	q.push(k); 
	tag[k] = true; 
	while (!q.empty())
	{
		int u = q.front(); 
		q.pop(); 
		tag[u] = false; 
		for (int j = head[u]; j; j = son[j])
		{
			int v = ver[j];
			if (dist[u] + edge[j] < dist[v])
			{
				dist[v] = dist[u] + edge[j];
				if (!tag[v])
				{
					q.push(v);
					tag[v] = true; 
				}
			}
		}
	}
}

int main()
{
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1; i <= m; i++)
	{
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		add(u, v, w);
	}
	
	SPFA(k);
	
	int ans = 0;
	for (int i = 1; i <= n; i++) 
		if (dist[n] > 0) ans = max(ans, dist[n]);
	printf("%d", ans);
	return 0;
}
