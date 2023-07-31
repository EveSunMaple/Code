#include <bits/stdc++.h>

using namespace std;
const int maxn = 2e6 + 10;
struct node {
	long long l, r;
};
vector<node> a, b, c[10], d[10];
int n, val[maxn];

void solve(int *a, int k, vector<node> &b) {
	for (int i = 0; i < (1 << k); i++) {
		long long s = 0;
		for (int j = 0; j < k; j++)
			if (i & (1 << j))
				s += a[j];
		b.push_back(node{s, 0});
	}
}

long long get_jin0(vector<node> &a, vector<node> &b, long long base) { //处理没有进位的答�?
	int point = b.size() - 1;
	long long ans = 0;
	for (int i = 0; i < a.size(); i++) {
		while (point >= 0 && a[i].r + b[point].r >= base)
			point--;
		ans += (point + 1);
	}
	return ans;
}

long long get_jin1(vector<node> &a, vector<node> &b, long long base) { //处理进位�?的使当前位为4的答�?
	int point = 0;
	long long ans = 0;
	int siz = b.size();
	for (int i = a.size() - 1; i >= 0; i--) {
		while (point <= siz - 1 && a[i].r + b[point].r < base)
			point++;
		ans += (b.size() - point);
	}
	return ans;
}


int main() {
	freopen("four.in", "r", stdin);
	freopen("four.out", "w", stdout);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &val[i]);
	solve(val + 1, n / 2, a);
	solve(val + 1 + n / 2, n - (n / 2), b);
	long long base = 1, ans = 0;
	for (int w = 0; w <= 8; w++) {
		for (int i = 0; i < 10; i++)
			c[i].clear(), d[i].clear();
		for (int i = 0; i < a.size(); i++)
			c[a[i].l % 10].push_back(node{a[i].l / 10, a[i].r});
		for (int i = 0; i < b.size(); i++)
			d[b[i].l % 10].push_back(node{b[i].l / 10, b[i].r});
		for (int i = 0; i < 10; i++) {       //枚举左半边的和的当前位的�?
			int k1 = (14 - i) % 10, k2 = (13 - i) % 10; //求右半边对应的和的当前位的数，k1表示在不进位的情况下的值，k2表示在后面有进位的情况下的需要的�?
			ans += get_jin0(c[i], d[k1], base) + get_jin1(c[i], d[k2], base);
		}
		int now = 0;
		for (int i = 0; i < 10; i++)
			for (int j = 0; j < c[i].size(); j++)
				a[now++] = node{c[i][j].l, c[i][j].r + i * base};
		now = 0;
		for (int i = 0; i < 10; i++)
			for (int j = 0; j < d[i].size(); j++)
				b[now++] = node{d[i][j].l, d[i][j].r + i * base};
		base *= 10;
	}
	printf("%lld\n", ans);
}
