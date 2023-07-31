#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#define N 2005
#define LL long long

using namespace std;

LL f[N]; // f[i] -> max_i
LL s[N]; // num_list
LL h[N]; // h_list
int n, m;

LL calc(int l, int r)
{
    LL sum_n = s[r] - s[l - 1];
    LL sum_h = h[r - l + 1];
    return sum_n + sum_h;
} 

int main()
{
    //freopen("coin.in", "r", stdin);
    //freopen("coin.out", "w", stdout);
  
    scanf("%d%d", &n, &m); // cin >> n >> m;
    for(int i = 1; i <= n; i++) 
    {
        scanf("%lld", &s[i]); // set num
        s[i] += s[i - 1];
    }
    for(int i = 1; i <= m; i++)
    {
        LL c, y;
        scanf("%lld%lld", &c, &y); // important -> %lld
        h[c] = y; // set M
    }
    for(int i = 1; i <= n; i++)
        h[i] += h[i - 1];

    // start DP
    for(int i = 1; i <= n; i++)
    {
        f[i] = calc(1, i); // init -> f[i]
        for(int j = 1; j <= i - 1; j++)
            f[i] = max(f[i], f[j - 1] + calc(j + 1, i)); // try other
        f[i] = max(f[i], f[i - 1]); // try back
    }

    printf("%lld", f[n]);

    return 0;
}