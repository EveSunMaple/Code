#include <bits/stdc++.h>

using namespace std;

int n, a[5001], c[1100001];

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	long long ans = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++)
			ans += c[a[i] ^ a[j]];
		for (int j = 1; j < i; j++)
			c[a[i] ^ a[j]]++;
	}
	printf("%lld\n", ans);
}