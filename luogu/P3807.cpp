#include <iostream>
#include <cstdio>
#define ll long long

using namespace std;

ll n, m, p;
ll x = 0, y = 0;

ll Exgcd(ll a, ll b, ll &x, ll &y)
{
    if (b == 0) 
    {
        x = 1, y = 0;
        return a;
    }
    ll d = Exgcd(b, a % b, x, y);
    ll z = x; x = y; y = z - (a / b) * y;

    return d;
}

ll C(ll a, ll b)
{
    ll up = 1, down = 1;
    for(ll i = 1; i <= a; i++)
    {
        up = (up * (b - i + 1)) % p;
        down = (down * i) % p;
    }

    Exgcd(down, p, x, y);
    x = (x % p + p) % p;

    return up * x;
}

int main()
{
    ll cnt;
    scanf("%lld", &cnt);
    
    for(ll i = 1; i <= cnt; i++)
    {
        scanf("%lld %lld %lld", &n, &m, &p);
        ll ans = C(n, m + n) % p;
        printf("%lld\n", ans);
    }

    return 0;
}