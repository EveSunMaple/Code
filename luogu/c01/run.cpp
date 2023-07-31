#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#define N 100005

using namespace std;

struct run
{
	int l, r;
}peo[N];

bool tag[N];
bool vis[N];
int temp;

bool cmp(run a, run b)
{
	//if(a.l < b.l) return true;
	//else if(a.l == b.l) return a.r < b.r;
	//return false;	
	return a.r < b.r;
}

void find(int n)
{
	for (int i = 1; i <= n; i++)
	{
		if(temp >= peo[i].l && temp <= peo[i].r && tag[peo[i].l] && !vis[i])
		{
			vis[i] = true;
			tag[++temp] = true;
			//printf("(%d,%d)\n", peo[i].l, peo[i].r);
			find(n);break;
		}
	}
}

void solve()
{
	memset(tag, 0, sizeof(tag));
	memset(vis, 0, sizeof(vis));
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", &peo[i].l);
	for (int i = 1; i <= n; i++) scanf("%d", &peo[i].r);
	sort(peo + 1, peo + 1 + n, cmp);
	temp = 0; tag[0] = true;
	find(n);
	printf("%d\n", temp);
}

int main()
{
	freopen("run.in", "r", stdin);
	freopen("run.out", "w", stdout);
	int t;
	scanf("%d", &t);
	while (t--) solve();
	return 0;
}
