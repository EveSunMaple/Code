#include<bits/stdc++.h>
using namespace std;
const int maxn = 1E6 + 5;
int n, m;
int tot_cycles;
int fa[maxn], dep[maxn], ans[maxn];
bool vis[maxn], not_top[maxn], single[maxn];
int f_point_down[maxn];
int f_down[maxn];
map<int, int> f_cycle_out[maxn];
map<int, int> f_cycle_in[maxn];
int top[maxn], bottom[maxn];
vector<int>E[maxn], belong[maxn], son[maxn];
inline int read() {
	char ch = getchar();
	while(!isdigit(ch)) {
		ch = getchar();
	}
	int x = ch - '0';
	ch = getchar();
	while(isdigit(ch)) {
		x = x * 10 + ch - '0';
		ch = getchar();
	}
	return x;
}
void push_cycle(int from, int to) {
	assert(dep[from] >= dep[to]);
	++tot_cycles;
	top[tot_cycles] = to;
	bottom[tot_cycles] = from;
	son[to].push_back(from);
	int S = from;
	while(from != to) {
		belong[from].push_back(tot_cycles);
		not_top[from] = true;
		from = fa[from];
	}
	belong[from].push_back(tot_cycles);
}
void dfs1(int u, int F, int d) {
	fa[u] = F;
	vis[u] = 1;
	dep[u] = d;
//	cout<<"NOW "<<u<<endl;
	for(auto v: E[u]) {
		if(v == F) {
			continue;
		}
		if(vis[v]) {
			if(dep[u] >= dep[v]) {
				push_cycle(u, v);
//				cout<<"PUSH "<<u<<" "<<tot_cycles<<endl;
			}
			continue;
		}
		dfs1(v, u, d + 1);
	}
	if(belong[u].size() == 0) {
		push_cycle(u, u);
//		cout<<"PUSH "<<u<<" "<<tot_cycles<<endl;
		single[u] = 1;
	}
	int id = 0;
	int id_bottom = 0;
	for(auto v: belong[u]) {
		if(top[v] != u && bottom[v] != u) {
			assert(id == 0);
			id = v;
		}
		if(bottom[v] == u) {
			assert(id_bottom == 0);
			id_bottom = v;
		}
	}
	assert(id == 0 || id_bottom == 0);
	if(!single[u]) {
		for(auto cycle: belong[u]) {
			if(cycle == id_bottom || cycle == id) {
				continue;
			}
			int v = bottom[cycle];
			int dis = dep[v] - dep[u];
			assert(dis >= 0);
			int now = 0;
			for(int d = 1; v != u; v = fa[v], d += 1) {
				int g = f_cycle_out[cycle][v];
				now = max(now, g + min(d, dis - d + 1));
			}
			f_down[cycle] = max(f_down[cycle], now);
		}
		if(id != 0 || id_bottom != 0) {
			id += id_bottom;
			for(auto v: E[u]) {
				if(dep[v] < dep[u] || not_top[v]) {
					continue;
				}
				if(!not_top[v]) {
					f_cycle_out[id][u] = max(f_cycle_out[id][u], f_point_down[v] + 1);
				}
			}
			for(auto cycle: belong[u]) {
				if(cycle == id || cycle == id_bottom) {
					continue;
				}
				f_cycle_out[id][u] = max(f_cycle_out[id][u], f_down[cycle]);
			}
		}
	}
	if(!not_top[u]) {
		for(auto v: E[u]) {
			if(dep[v] < dep[u] || not_top[v]) {
				continue;
			}
			f_point_down[u] = max(f_point_down[u], f_point_down[v] + 1);
		}
		for(auto cycle: belong[u]) {
			if(cycle == id || cycle == id_bottom) {
				continue;
			}
			f_point_down[u] = max(f_point_down[u], f_down[cycle]);
		}
	}
}
int val[maxn * 2], tmp0[maxn], tmp[maxn], q[maxn * 2], ql, qr;
void clear() {
	ql = 1;
	qr = 0;
}
void push(int x, int pos) {
	while(ql <= qr && val[q[qr]] <= x) {
		--qr;
	}
	q[++qr] = pos;
}
void calc(int len) {
//	cout<<"CALC "<<len<<endl;
//	for(int i = 0; i < len; ++i) {
//		cout<<val[i] <<" ";
//	}cout <<endl;
	clear();
	assert(len > 2);
	if(len == 1) {
		tmp[0] = 0;
		return;
	}
	for(int i = len; i < len * 2; ++i) {
		val[i] = val[i - len];
	}
	for(int i = 0; i < len * 2; ++i) {
		val[i] += i;
	}
	clear();
	int seg = len / 2;
	for(int i = 0; i < seg; ++i) {
		push(val[i], i);
	}
//	cout << "FIRST " << len << ' ' << seg << endl;
//	for(int i = 0; i < len * 2; ++i) {
//		cout << val[i] << ' ';
//	}
//	cout << endl;
	for(int i = 0; i < len; ++i) {
		while(ql <= qr && q[ql] <= i) {
			++ql;
		}
		push(val[i + seg], i + seg);
		tmp0[i] = val[q[ql]] - i;
	}
	for(int i = 0; i < len; ++i) {
		tmp[i] = tmp0[i];
	}
	clear();
	for(int i = 0; i < len * 2; ++i) {
		val[i] -= i;
	}
	reverse(val, val + len * 2);
	for(int i = 0; i < len * 2; ++i) {
		val[i] += i;
	}
	seg = len / 2;
//	cout << "SECONDO " << seg << endl;
//	for(int i = 0; i < len * 2; ++i) {
//		cout << val[i] << ' ';
//	}
//	cout << endl;
	for(int i = 0; i < seg; ++i) {
		push(val[i], i);
	}
	for(int i = 0; i < len * 2; ++i) {
		while(ql <= qr && q[ql] <= i) {
			++ql;
		}
		push(val[i + seg], i + seg);
		tmp0[i] = val[q[ql]] - i;
	}
	for(int i = 0; i < len; ++i) {
		tmp[i] = max(tmp[i], tmp0[len - i - 1]);
	}
}
void dfs2(int u, int F, int up) {
	vis[u] = 1;
	int id = 0;
	int id_bottom = 0;
	for(auto v: belong[u]) {
		if(top[v] != u && bottom[v] != u) {
			id = v;
		}
		if(bottom[v] == u) {
			id_bottom = v;
		}
	}
	if(id) {
		up = 0;
	}
	if(id_bottom && !single[u]) {
		up = f_cycle_in[id_bottom][u];
	}
	if(single[u]) {
		f_cycle_in[id_bottom][u] = up;
		f_cycle_out[id_bottom][u] = f_point_down[u];
	} else {
		vector<int> pre, suf, what;
		int g = 0;
		if(id) {
			g = f_cycle_in[id][u];
		}
		for(auto v: E[u]) {
			if(dep[v] != dep[u] + 1 || not_top[v]) {
				continue;
			}
			g = max(g, f_point_down[v] + 1);
		}
		for(auto cycle: belong[u]) {
			if(top[cycle] == u) {
				pre.push_back(f_down[cycle]);
				suf.push_back(f_down[cycle]);
				what.push_back(cycle);
			}
		}
		int len = pre.size();
		for(int i = 1; i < len; ++i) {
			pre[i] = max(pre[i], pre[i - 1]);
		}
		for(int i = len - 2; i >= 0; --i) {
			suf[i] = max(suf[i], suf[i + 1]);
		}
		for(int i = 0; i < len; ++i) {
			int cycle = what[i];
			f_cycle_out[cycle][u] = max(g, max(f_cycle_out[cycle][u], up));
			if(i != 0) {
				f_cycle_out[cycle][u] = max(f_cycle_out[cycle][u], pre[i - 1]);
			}
			if (i != len - 1) {
				f_cycle_out[cycle][u] = max(f_cycle_out[cycle][u], suf[i + 1]);
			} 
		}
	}
	if(!single[u]) {
		for(auto cycle: belong[u]) {
			if(top[cycle] != u) {
				continue;
			}
			int v = bottom[cycle];
			int len = 0;
			for(; v != fa[u]; v = fa[v], ++len) {
				val[len] = f_cycle_out[cycle][v];
			}
			calc(len);
			for(v = bottom[cycle], len = 0; v != fa[u]; v = fa[v], ++len) {
				f_cycle_in[cycle][v] = tmp[len];
			}
		}
	}
	int gg = 0;
	for(auto cycle: belong[u]) {
		gg = max(gg, f_cycle_in[cycle][u]);
	}
	if(single[u]) {
		gg = max(gg, f_cycle_in[id_bottom][u]);
	} else if(id_bottom || id == 0) {
		gg = max(gg, up);
	}
	vector<int> pre, suf;
	for(auto v: E[u]) {
		if(dep[v] != dep[u] + 1) {
			continue;
		}
		if(not_top[v]) {
			pre.push_back(gg);
			suf.push_back(gg);
		} else {
			int ggg = f_point_down[v] + 1;
			pre.push_back(ggg);
			suf.push_back(ggg);
		}
	}
	int len = pre.size();
	for(int i = 1; i < len; ++i) {
		pre[i] = max(pre[i], pre[i - 1]); 
	}
	for(int i = len - 2; i >= 0; --i) {
		suf[i] = max(suf[i], suf[i + 1]);
	}
	int k = 0;
	for(auto v: E[u]) {
		if(dep[v] != dep[u] + 1) {
			continue;
		}
		up = gg;
		if(k != 0) {
			up = max(up, pre[k - 1]);
		}
		if(k != len - 1) {
			up = max(up, suf[k + 1]);
		}
		++k;
		dfs2(v, u, up + 1);
	}
}
int main() {
	freopen("shadow.in", "r", stdin);
	freopen("shadow.out", "w", stdout);
	ios::sync_with_stdio(false);
	n = read();
	m = read();
	for(int i = 1; i <= m; ++i) {
		int x = read(), y = read();
		E[x].push_back(y);
		E[y].push_back(x);
	}
	dfs1(1, 0, 0);
	for(int i = 1; i <= n; ++i) {
		if(!vis[i]) {
			cout << "Not connected" << endl;
			assert(0);
		}
	}
	memset(vis, 0, sizeof(vis));
	dfs2(1, 0, 0);
//	for(int i = 1; i <= n; ++i) {
//		cout << f_point_down[i] <<" ";
//	}cout<<endl;
	for(int u = 1; u <= n; ++u) {
		int cycle = belong[u][0];
		assert(cycle != 0);
		cout << max(f_cycle_out[cycle][u], f_cycle_in[cycle][u]) << ' ';
	}
	cout << endl;
	return 0;
}

