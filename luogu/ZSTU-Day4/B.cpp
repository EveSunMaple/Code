#pragma GCC optimize ("O2")
#include <iostream>
#include <cstring>
#include <cstdio>
#define N 200005
#define ll long long
#define i128 __int128

using namespace std;

ll a[N];
ll sum[N];
ll mul[N];

int main()
{
    int n, k;
    mul[0] = 1;
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld", &a[i]);     
        sum[i] = sum[i - 1] + a[i];   
        mul[i] = mul[i - 1] * a[i];                
    }
    ll ans = 0;
    for (int l = 1; l < n; l++)
    {
        for (int r = l + 1; r <= n; r++)
        {
            if (l == 1 && r == n) continue;
            if ((mul[r] / mul[l - 1]) % (sum[r] - sum[l - 1])) continue;
            ans++;
        }
    }
    printf("%lld", ans);
    return 0;
}