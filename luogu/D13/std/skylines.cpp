#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std;
using i64 = long long;

const int N = 2e5 + 5;
vector<vector<pair<int, int>>> G(N);
int n;
int c[N], dist[N], ans[N], _min[N];
int choose[N];

inline void init() {

}

void dfs(int x, int from) {
    _min[x] = dist[x] - c[x];
    int tmin = INT_MAX;
    int minc = 0;
    for (auto edge : G[x]) {
        int y = edge.first; if (y == from) continue;
        dist[y] = dist[x] + edge.second;
        dfs(y, x);
        if (_min[y] < tmin) tmin = _min[y], minc = 1;
        else if (_min[y] == tmin) minc++;
    }
    if (_min[x] < tmin) minc = 0;
    else if (_min[x] > tmin) _min[x] = tmin;
    else minc++;
    if (minc == 1 && _min[x] != dist[x] - c[x]) {
        int t;
        int smin = dist[x] - c[x]; 
        for (auto edge : G[x]) {
            int y = edge.first; if (y == from) continue;
            if (_min[y] == _min[x]) t = y;
            else smin = min(smin, _min[y]), choose[y] = _min[x];
        }
        choose[t] = smin;
    }
    else {
        for (auto edge : G[x]) {
            int y = edge.first; if (y == from) continue;
            choose[y] = _min[x];
        }
    }
    ans[x] = tmin < INT_MAX ? c[x] - dist[x] + tmin : INT_MAX;
}

void dfs2(int x, int from, int t) {
    if (t < INT_MAX) ans[x] = min(ans[x], dist[x] + c[x] + t);
    for (auto edge : G[x]) {
        int y = edge.first; if (y == from) continue;
        dfs2(y, x, min(t, choose[y] - 2 * dist[x]));
    }
}

inline void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> c[i];
    for (int i = 1; i < n; i++) {
        int x, y, z; cin >> x >> y >> z;
        G[x].push_back({y, z});
        G[y].push_back({x, z});
    }
    dfs(1, 0);
    dfs2(1, 0, INT_MAX);
    int q; cin >> q;
    while (q--) {
        int x; cin >> x;
        cout << ans[x] << '\n';
    }
}

int main()
{
	fastio;
	freopen("skylines.in","r",stdin);
	freopen("skylines.out","w",stdout);
	int t = 1; 
	// cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}
/*

*/