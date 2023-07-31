#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
using namespace std;

const int maxn = 100086, Mod = 10086;

struct Edge
{
	int next;
	int to;
} edge[maxn * 2];

int n, head[maxn], num_edge, val[maxn], f[maxn], ans;
bool visit[maxn];

void add_edge(int from, int to)
{
	edge[++num_edge].next = head[from];
	edge[num_edge].to = to;
	head[from] = num_edge;

	edge[++num_edge].next = head[to];
	edge[num_edge].to = from;
	head[to] = num_edge;
}

void DP(int now)
{
	long long tmp = 0, temp = 0;
	visit[now] = 1;
	for (int i = head[now]; i != 0; i = edge[i].next)
		if (!visit[edge[i].to])
		{
			DP(edge[i].to);
			tmp += f[edge[i].to];
			temp += f[edge[i].to] * f[edge[i].to];
		}
	f[now] = ((tmp + 1) * val[now]) % Mod;
	tmp = tmp * tmp;
	tmp = (tmp - temp) / 2;
	tmp %= Mod;
	tmp = (tmp * val[now]) % Mod;
	ans = (ans + f[now] + tmp) % Mod;
}

int main()
{
	freopen("count.in", "r", stdin);
	freopen("count.out", "w", stdout);
	int u, v;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &val[i]);
		val[i] %= Mod;
	}
	for (int i = 1; i < n; i++)
	{
		scanf("%d %d", &u, &v);
		add_edge(u, v);
	}
	DP(1);
	printf("%d\n", ans);
	// system("pause");
	return 0;
}
