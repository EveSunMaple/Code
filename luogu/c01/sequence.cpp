#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#define N 100005

using namespace std;

int num[N];

bool cmp(int a, int b)
{
    return a > b;
}

void solve()
{
    memset(num, 0, sizeof(num));
    int n; scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &num[i]);
    sort(num + 1, num + 1 + n, cmp);
    long long ans = abs(num[1] - num[n / 2 + 1]);
    int l = 2, r = n;
    int temp = num[1];
    for (int i = 1; l <= r; i++)
    {
        if (i & 1)
        {
            ans += abs(temp - num[r]);
            temp = num[r--];
        }
        else 
        {
            ans += abs(temp - num[l]);
            temp = num[l++];
        }
    }
    printf("%lld\n", ans);
}

int main()
{
	freopen("sequence.in", "r", stdin);
	freopen("sequence.out", "w", stdout);
    int t;
    scanf("%d", &t);
    while (t--) solve();
    return 0;
}
