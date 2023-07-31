#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

void solve()
{
    int n;
    scanf("%d", &n);
    int temp = 0, ans;
    for (int i = 1; i <= n; i++)
    {
        int now;
        scanf("%d", &now);
        if (temp && now - temp != 1) ans = i;
        temp = now;
    }
    printf("%d\n", ans);
}

int main()
{
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    int n;
    scanf("%d", &n);
    while (n--) solve();
    return 0;
}