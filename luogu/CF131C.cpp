#include <iostream>
#define ll long long

using namespace std;

ll gcd(ll a, ll b)
{
    return b == 0 ? a : gcd(b, a % b);
}

ll solve(ll a, ll b)
{
    ll up = 1, down = 1;
    ll n = a, t = 1;
    
    for(ll i = 1; i <= b; i++)
    {
        up *= n;
        n--;
        down *= t;
        t++;
        ll d = gcd(up, down);
        up /= d;
        down /= d;
    }

    return up / down;
}

int main()
{
    ll n = 0, m = 0, t = 0;
    scanf("%lld %lld %lld", &n, &m ,&t);

    ll ans = 0;

    for(ll w = 1; w <= m; w++)
    {
        if(4 + w <= t)
        {
            ll cnt_w = solve(m, w);
            ll cnt_m = solve(n, t - w);
            ans += cnt_w * cnt_m;
        }
    }

    printf("%lld", ans);

    return 0;
}