#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <cmath>
#define fastio                   \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0)
#define N 1000005
#define i128 __int128
#define mod 1000000007

using namespace std;

// i128 gcd(int a, int b)
// {
//     return a == 0 ? b : gcd(a % b, a);
// }

// i128 calc(int sm, int la)
// {
//     i128 up = 1, down = 1;
//     for (int i = 1; i <= sm; i++)
//     {
//         up *= la;
//         down *= sm;
//         i128 d = gcd(up, down);
//         up /= d;
//         down /= d;
//     }
//     return up / down;
// }

vector<i128> site;

i128 dfs(int line, int ins, int have)
{
    i128 temp = site[line];
    for (int i = line; i <= ins; i++)
    {
        if (have - i <= 0)
            continue;
        temp = (temp * dfs(i, ins, have - 1)) % mod;
    }
    return temp;
}

void solve()
{
    // int n, k;
    // site.clear();
    // site.push_back(1);
    // scanf("%d%d", &n, &k);
    // i128 temp = 1, other = 1;
    // int ins = n - k + 1, ans = 0;
    // for (int i = 1; i <= k; i++)
    // {
    //     temp *= k - i; // k - 1 -> n
    //     other = other * (n - i + 1) / i;
    //     site.push_back(temp * other);
    // }
    // for (int i = 1; i <= ins; i++)
    // {
    //     ans = (i128)(ans + site[k - 1] * dfs(i, ins, ins)) % mod;
    // }
    // ====================================
    // if (k > n) ins = n;
    // else ins = k - 1;
    // for (int i = 1; i <= ins; i++)
    // {
    //     temp = temp * (k - i + 1) / i;
    //     site.push_back(temp);
    // }
    // for (int i = 0; i <= ins; i++)
    // {
    //     ans = (i128)(ans + dfs(i, ins, n)) % mod;
    // }
    int n, k;
    site.clear();
    site.push_back(1);
    scanf("%d%d", &n, &k);
    i128 temp = 1, other = k;
    int ins, ans = 0;
    if (k > n)
        ins = n;
    else
        ins = k - 1;
    for (int i = 1; i <= ins; i++)
    {
        other *= i;
        temp = temp * (k - i + 1) / i;
        site.push_back(temp);
    }
    for (int i = 0; i <= ins; i++)
    {
        ans = (i128)(ans + dfs(i, ins, n)) % mod;
    }
    ans = (ans * other) % mod;
    printf("%d\n", ans);
}

int main()
{
    fastio;
    freopen("maruyu.in", "r", stdin);
    freopen("maruyu.out", "w", stdout);
    int n;
    scanf("%d", &n);
    while (n--)
        solve();
    return 0;
}