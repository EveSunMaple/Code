#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#define mod 1000000007
#define N 100005

using namespace std;

//int cnt[N][32];
long long a[N];
long long ans;
long long other[32] = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384, 32768, 65536, 131072, 262144, 524288, 1048576, 2097152, 4194304, 8388608, 16777216, 33554432, 67108864, 134217728, 268435456, 536870912, 1073741824};
long long cnt[32];
int n;

bool cmp(long long x, long long y)
{
    return x > y;
}

int main()
{
	freopen("andsum.in", "r", stdin);
	freopen("andsum.out", "w", stdout);
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
    sort(a + 1, a + 1 + n, cmp);
    for (int i = n; i >= 1; i--)
    {
        long long temp = 0;
        for (int j = 0; j < 31; j++)
        {
            if((a[i] >> j) & 1)
            {
                temp = (temp + (cnt[j] * (other[j] % mod)) % mod) % mod;
                cnt[j] += 1;
            }
        }
        ans = (ans + (a[i] * temp) % mod) % mod;
    }
    printf("%lld", ans);
    return 0;
}
