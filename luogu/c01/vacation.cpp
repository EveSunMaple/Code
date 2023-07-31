#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#define N 100005

using namespace std;

int DP[N][3];
int val[N][3];

void solve()
{
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d%d%d", &val[i][0], &val[i][1], &val[i][2]);
	}
	DP[1][0] = val[1][0];
	DP[1][1] = val[1][1];
	DP[1][2] = val[1][2];
	for (int i = 1; i < n; i++)
	{
		DP[i + 1][0] = max(DP[i][1], DP[i][2]) + val[i + 1][0];
		DP[i + 1][1] = max(DP[i][0], DP[i][2]) + val[i + 1][1];
		DP[i + 1][2] = max(DP[i][1], DP[i][0]) + val[i + 1][2];
	}
	int ans = max(DP[n][0], max(DP[n][1], DP[n][2]));
	printf("%d\n", ans);
}

int main()
{
	freopen("vacation.in", "r", stdin);
	freopen("vacation.out", "w", stdout);
	int t;
	scanf("%d", &t);
	while (t--) solve();
	return 0;
}
