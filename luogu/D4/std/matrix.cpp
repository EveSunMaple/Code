#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
const int maxn = 3010;
const int Mod = 1000000007;
int dp[maxn][maxn], same[maxn][maxn];
int sum1[maxn][maxn], sum2[maxn][maxn];
char c[maxn][maxn];

int main() {
	freopen("matrix.in", "r", stdin);
	freopen("matrix.out", "w", stdout);
	int N, M, K, ans;
	scanf("%d%d%d", &N, &M, &K);
	rep(i, 1, N) scanf("%s", c[i] + 1);
	rep(i, 1, M) {
		dp[1][i] = 1;
		same[1][i] = (i != 1 && c[1][i] == c[1][i - 1]);
		sum1[1][i] = sum1[1][i - 1] + dp[1][i];
		sum2[1][i] = sum2[1][i - 1] + same[1][i];
	}
	rep(i, 2, N) {
		rep(j, 1, M) {
			dp[i][j] = ((sum1[i - 1][min(M, j + K)] - sum1[i - 1][max(0, j - K - 1)]) % Mod + Mod) % Mod - ((sum2[i - 1][min(M,
			           j + K)] - sum2[i - 1][max(0, j - K)]) % Mod + Mod) % Mod;
			if (dp[i][j] < 0)
				dp[i][j] += Mod;
			if (j == 1 || c[i][j] != c[i][j - 1])
				same[i][j] = 0;
			else
				same[i][j] = ((sum1[i - 1][min(M, j + K - 1)] - sum1[i - 1][max(0,
				               j - K - 1)]) % Mod + Mod) % Mod - ((sum2[i - 1][min(M, j + K - 1)] - sum2[i - 1][max(0, j - K)]) % Mod + Mod) % Mod;
			if (same[i][j] < 0)
				same[i][j] += Mod;
			sum1[i][j] = (sum1[i][j - 1] + dp[i][j]) % Mod;
			sum2[i][j] = (sum2[i][j - 1] + same[i][j]) % Mod;
		}
	}
	ans = 0;
	rep(i, 1, M) ans = ((ans + (dp[N][i] - same[N][i]) % Mod) % Mod + Mod) % Mod;
	printf("%d\n", ans);
	return 0;
}