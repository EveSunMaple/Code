#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(false);std::cin.tie(0);std::cout.tie(0)
#define x first
#define y second
using i64 = long long;
using std::cin;
using std::cout;

const int N = 2e4 + 5, M = 2e3 + 5;

inline void init() {

}

int f[M][M], g[M][M];
inline void solve() {
    int n, m; cin >> n >> m;
    std::vector<int> a(n + 1), pos(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        pos[i] = i % m;
    }
    memset(f, 0x3f, sizeof f);
    memset(g, 0x3f, sizeof f);
    for (int i = 2; i <= m; i++) 
        for (int j = i-1; j >= 1; j--) {
            f[pos[i]][i-j] = a[i] + a[j];
            g[pos[i]][i-j] = std::min(g[pos[i]][i-j-1], f[pos[i]][i-j]);
        }

    for (int i = m+1; i <= n; i++) 
        for (int j = i-1; j >= i-m+1; j--) {
            f[pos[i]][i-j] = a[i] + g[pos[j]][j-(i-m)];
            g[pos[i]][i-j] = std::min(g[pos[i]][i-j-1], f[pos[i]][i-j]);
        }
    
    int ans = INT_MAX;
    for (int i = n - m + 1; i <= n; i++) {
		for (int j = i - 1; j >= n - m + 1; j--) {
			ans = std::min(ans, f[pos[i]][i - j]);
		}
	}
    cout << ans << '\n';
}

int main()
{
	fastio;
	freopen("friend.in","r",stdin);
	freopen("friend.out","w",stdout);
	int t = 1; 
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}
/*

*/