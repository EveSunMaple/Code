#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <queue>
#include <map>

#define N 4005
#define M 15
#define mod 1000000007
#define mod2 100000000
#define ll long long
#define maxi(a,b) (a)>(b)? (a) : (b)
#define mini(a,b) (a)<(b)? (a) : (b)

using namespace std;

int cnt;
int p;
int i, j;
int a[N][N];
int c[N][N];
int cc[N];
int ans[N], pp[N];

int main() {
	freopen("multiplication.in", "r", stdin);
	freopen("multiplication.out", "w", stdout);
	cnt = 1;
	scanf("%d", &p);
	for (i = 0; i < p; i++) {
		for (j = 1; j <= p; j++) {
			scanf("%d", &a[i][2 * j - 1]);
			cc[ a[i][2 * j - 1] ]++;
			scanf("%d", &a[i][2 * j]);
			cc[ a[i][2 * j] ]++;
		}
	}

	int ma = cc[0];
	int index = 0;
	for (i = 0; i < p; i++) {
		if (cc[i] > ma) {
			ma = cc[i];
			index = i;
		}
	}
	ans[0] = index;

	memset(cc, 0, sizeof(cc));

	for (i = 0; i < p; i++) {
		for (j = 1; j <= p; j++) {
			if (c[i][ a[i][2 * j - 1] ] == 0) {
				c[i][ a[i][2 * j - 1] ] = 1;
				cc[i]++;
			}
		}
		if (cc[i] == 1) {
			if (ans[0] != i)
				ans[1] = i;
		} else {
			ans[ cc[i] ] = i;
		}
	}
	for (int i = 0; i < p; i++)
		pp[ans[i]] = i;
	for (i = 0; i < p; i++)
		printf("%d%c", pp[i], " \n"[i == p - 1]);
}