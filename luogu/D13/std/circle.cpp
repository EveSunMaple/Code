#include <bits/stdc++.h>
using namespace std;
int low[600010], dfn[600010], n, m, cnt;
int sta[600010], top, insta[600010];
vector < int > son[600010];
int idcnt, id[600010];

void tarjan(int x) {
	dfn[x] = low[x] = ++cnt;
	insta[sta[++top] = x] = 1;
	for (auto v : son[x]) {
		if (!dfn[v])
			tarjan(v), low[x] = min(low[x], low[v]);
		else if (insta[v])
			low[x] = min(low[x], dfn[v]);
	}
	if (dfn[x] == low[x]) {
		idcnt++;
		do {
			id[sta[top]] = idcnt;
			insta[sta[top]] = 0;
		} while (sta[top--] != x);
	}
}

int main() {
	freopen("circle.in", "r", stdin);
	freopen("circle.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++) {
		int u, v;
		scanf("%d%d", &u, &v);
		son[3 * u - 0].push_back(3 * v - 1);
		son[3 * u - 1].push_back(3 * v - 2);
		son[3 * u - 2].push_back(3 * v - 0);
	}
	for (int i = 1; i <= 3 * n; i++)
		if (!dfn[i])
			tarjan(i);
	int ans = 0;
	for (int i = 1; i <= n; i++)
		if (id[3 * i] == id[3 * i - 1]) {
			ans++;
		}
	printf("%d\n", ans);
}