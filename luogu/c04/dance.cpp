#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>

using namespace std;

void init(int l, int r, int &ans)
{
    if (l == r) return;
    if (r - l == 1)
    {
        ans += l * r;
        return;
    }
    init(l, (l + r) / 2, ans);
    init((l + r) / 2 + 1, r, ans);
}

void solve()
{
    int n;
    scanf("%d", &n);
    int ans = 0;
    init(1, n, ans);
    printf("%d\n", ans);
}

int main()
{
    freopen("dance.in", "r", stdin);
    freopen("dance.out", "w", stdout);
    int n;
    scanf("%d", &n);
    while (n--) solve();
    return 0;
}