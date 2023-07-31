#include <iostream>
#include <cstring>
#include <cstdio>
#define N 1048576
#define ll long long

using namespace std;

ll n, ans;
ll cnt[N];
int a[N];

int main()
{
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    scanf("%lld", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
    }
    // cnt[a[1] ^ a[2]]++;
    for (int k = 1; k <= n; k++)
    {
        for (int l = k + 1; l <= n; l++)
        {
            ans += cnt[a[k] ^ a[l]];
        }
        for (int i = 1; i < k; i++)
            cnt[a[i] ^ a[k]]++;
    }
    printf("%lld", ans);
    return 0;
}
