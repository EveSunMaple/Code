#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#define N 200005

using namespace std;

int a[N];
pair<int, int> DP[N][2];

int main()
{
	freopen("friend.in", "r", stdin);
	freopen("friend.out", "w", stdout);
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n, m, ans = 0;
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= n; i++) 
            scanf("%d", &a[i]);
        int crd = 0;
        int temp = 1e9;
        for (int j = 1; j <= m - 1; j++)
        {
            if (a[j] + a[j + 1] < temp)
            {
                temp = a[j] + a[j + 1];
                crd = j + m;
            }
        }
        for (int i = crd; i <= n; i += m)
        {
            if (i + 1 > n) ans += min(a[i], a[i - 1]);
            else ans += a[i] + a[i + 1];
        }
        printf("%d\n", ans + temp);
    }
    return 0;
}