#include <iostream>
#include <cstdio>
#define ll long long
#define P 998244353

using namespace std;

ll n, m;
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
    //      a
    //  C 
    //      b
    ll up = 1, down = 1;
    for(ll i = 1; i <= a; i++)
    {
        up = (up * (b - i + 1)) % P;
        down = (down * i) % P;
    }

    Exgcd(down, P, x, y);
    x = (x % P + P) % P;

    return up * x;
}

ll pow(ll a, ll b, ll p)
{
    ll res = 1;
    for(; b > 0;)
    {
        if(b & 1)
            res = res * a % p;
        a = a * a % p;
        b >>= 1;
    }

    return res % p;
}

int main()
{
    scanf("%lld %lld", &n, &m);
    ll cnt = C(n - 1, m) % P;
    ll mul = pow(2, n - 3, P);
    ll ans = (((cnt % P) * mul) % P * ((n - 2) % P)) % P;

    printf("%lld", ans);

    return 0;
}