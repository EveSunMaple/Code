#include <iostream>
#include <cstring>
#include <cstdio>
#define mod 10007
#define ll long long

using namespace std;

ll pow(ll a, ll b)
{
    ll ans = 1;
    ll res = a;
    while (b > 0)
    {
        if (b & 1)
        {
            ans = (ans * res) % mod;
        }
        res = (res * res) % mod;
        b >>= 1;
    }
    return ans;
}

// ll solve(ll ran, ll tag)
// {
//     ll sum = 2;
//     for (ll i = tag; i <= ran; i++)
//     {
//         ll l = i - 2 - tag;
//         ll r = ran - 1 - i;
//         if (l >= 1) sum = (sum + solve(l, 1)) % mod;
//         if (l >= 2) sum = (sum + solve(l, 2)) % mod;
//         if (r >= 1) sum = (sum + solve(r, 1)) % mod;
//         if (r >= 2) sum = (sum + solve(r, 2)) % mod;
//     }
//     return sum;
// }

int main()
{
    // ll a, b;
    // scanf("%lld%lld", &a, &b);
    // printf("%lld", pow(a, b));
    ll n;
    scanf("%lld", &n);
    ll has = n - 3;
    ll all = pow(2, n);
    // ll ans = solve(n, 1) + solve(n, 2);
    ll ans = all;
    ll i = 1;
    // while (has > 0)
    // {
    //     ll cut = pow(2, has);
    //     printf("%lld %lld\n", cut, has);
    //     ans = (ans - cut * has * i + mod) % mod;
    //     has >>= 1; i <<= 1;
    // }
    while (has > 0)
    {
        ll cut = pow(2, has);
        // printf("%lld %lld\n", cut, has);
        ans = (ans - cut * has * i + mod) % mod;
        has >>= 1; i <<= 1;
    }
    printf("%d", ans);
    return 0;
}