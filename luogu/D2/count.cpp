#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#define N 100005

using namespace std;

struct node
{
	int ver;
	int nxt;
}edge[N * 2];

//vector<int> up[N];
vector<int> down[N];
int head[N * 2];
int value[N];
int n, ans;
int tot;

void add(int u, int v)
{
	tot++;
	edge[tot].ver = v;
	edge[tot].nxt = head[u];
	head[u] = tot;
} 

void dfs(int u, int from)
{
	//for (int j = 0; j < up[from].size(); j++) 
	//{
	//	up[u].push_back((value[u] * down[from][j]) % 10086);
	//	ans = (ans + value[u] * up[from][j]) % 10086;
	//    printf("ans += value[%d](%d) * up[%d][%d](%d)\n", u, value[u], from, j, up[from][j]);
	//}
	for (int i = head[u]; i; i = edge[i].nxt)
	{
		int v = edge[i].ver;
		if (v == from) continue;
		//up[v].push_back(value[v]);
		down[v].push_back(value[v]);
		ans = (ans + value[v]) % 10086;
		//printf("ans += value[%d](%d)\n", v, value[v]);
		dfs(v, u);
		int now = down[u].size();
		for (int j = 0; j < down[v].size(); j++) 
		{
			down[u].push_back((value[u] * down[v][j]) % 10086);
			for (int t = 0; t < now; t++)
			{
				ans = (ans + down[u][t] * down[v][j]) % 10086;
		  		//printf("ans += down[%d][%d](%d) * down[%d][%d](%d)\n", u, t, value[u], v, j, down[v][j]);
			}
		}
	}
}

int main()
{
	freopen("count.in", "r", stdin);
	freopen("count.out", "w", stdout);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", &value[i]);
	for (int i = 1; i < n; i++)
	{
		int u, v;
		scanf("%d%d", &u, &v);
		add(u, v); add(v, u);
	}
	add(0, 1);
	dfs(0, 0);
	printf("%d", ans);
	return 0;	
} 
