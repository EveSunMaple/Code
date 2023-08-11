#include<bits/stdc++.h>
#define mod 998244353
using namespace std;
typedef pair<int, int> pii;
const int maxn = 300005;
int n, m;
int size, head[maxn * 2];
bool vis[maxn * 2], color[maxn * 2];
inline int read() {
	char c = getchar();
	while(!isdigit(c)) {
		c = getchar(); 
	}
	int x = c - '0';
	c = getchar();
	while(isdigit(c)) {
		x = x * 10 + c - '0';
		c = getchar();
	}
	return x;
}
struct edge {
	int to, next;
	bool w;
}E[maxn * 4];
int row(int x) {
	return x;
}
int col(int x) {
	return n + x;
}
void addE(int u, int v, bool w) {
	E[++size].to = v;
	E[size].next = head[u];
	E[size].w = w;
	head[u] = size;
}
void add(int x, int y, bool w) {
	addE(x, y, w);
	addE(y, x, w);
}
void clear() {
	size = 0;
	memset(head, 0, sizeof(head));
	memset(E, 0, sizeof(E));
	memset(vis, 0, sizeof(vis));
	memset(color, 0, sizeof(color));
}
bool dfs(int u, bool c) {
	vis[u] = true;
	color[u] = c;
	bool flag = true;
	for(int i = head[u]; i; i = E[i].next) {
		int v = E[i].to;
		bool nc = c ^ E[i].w;
		if(vis[v]) {
			if(nc != color[v]) {
				flag = false;
			}
			continue;
		}
		flag &= dfs(v, nc);
	}
	return flag;
}
bool try_color(int u, bool c) {
	if(!vis[u]) {
		return dfs(u, c);
	} else {
		return color[u] == c;
	}
}
int get() {
	int k = 0;
	for(int i = 2; i <= n; ++i) {
		int x = row(i);
		if(!vis[x]) {
			bool flag = try_color(x, 0);
			if(flag == false) {
				return 0;
			}
			++k;
		}
	}
	for(int i = 2; i <= m; ++i) {
		int x = col(i);
		if(!vis[x]) {
			bool flag = try_color(x, 0);
			if(flag == false) {
				return 0;
			}
			++k;
		}
	}
	int ans = 1;
	for(int i = 1; i <= k; ++i) {
		ans = ans * 2 % mod;
	}
	return ans;
}
int solve() {
	int k;
	n = read();
	m = read();
	k = read();
	clear();
	bool ul = false;
	bool what = 0;
	bool body = false;
	map<pii, bool> check_vis;
	vector<pii> sign;
	while(k--) {
		int x = read(), y = read(), d = read();
		assert(check_vis[pii(x, y)] == false);
		check_vis[pii(x, y)] = true;
		if(x == 1 && y == 1) {
			ul = true;
			what = d;
		} else if(x == 1) {
			sign.push_back(pii(col(y), d));
		} else if(y == 1) {
			sign.push_back(pii(row(x), d));
		} else {
			add(row(x), col(y), d);
			body = true;
		}
	}
	int ans0 = 0;
	for(int i = 0; i < sign.size(); ++i) {
		bool flag = try_color(sign[i].first, sign[i].second);
		if(flag == false) {
			goto end0;
		}
	}
	ans0 = get();
	end0:;
	int ans1 = 0;
	memset(vis, 0, sizeof(vis));
	memset(color, 0, sizeof(color));
	for(int u = 1; u <= n + m; ++u) {
		for(int i = head[u]; i; i = E[i].next) {
			E[i].w ^= 1;
		}
	}
	for(int i = 0; i < sign.size(); ++i) {
		bool flag = try_color(sign[i].first, sign[i].second);
		if(flag == false) {
			goto end1;
		}
	}
	ans1 = get();
	end1:;
	if(ul) {
		if(what) {
			return ans1;
		} else {
			return ans0;
		}
	} else {
		return (ans0 + ans1) % mod;
	}
}
int main() {
//	freopen("pai.in", "r", stdin);
	freopen("logist.in", "r", stdin);
	freopen("logist.out", "w", stdout);
	ios::sync_with_stdio(false);
	int T = read();
	while(T--) {
		cout << solve() << endl;
	}
	return 0;
}

