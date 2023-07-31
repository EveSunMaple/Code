#include <iostream>
#include <cmath>
#define ll long long

using namespace std;

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

ll qmul(ll a, ll b, ll p)
{
	a %= p;
    b = (b % p + p) % p;
	ll res = 0;
	while (b)
	{
		if (b & 1) { res = (res + a) % p; }
		a = (a + a) % p;
		b >>= 1;
	}
	return res;
}

void sp(int n)
{
	ll r ,l;
    for(ll i = 1; i <= n; i++)
    {
        scanf("%lld%lld", &r, &l);
    }
	cout << -1 << endl;
}

void solve(int n)
{
    ll a1, a2;
    ll b1, b2;
    scanf("%lld%lld", &a1, &b1);
    for(ll i = 2; i <= n; i++)
    {
        scanf("%lld%lld", &a2, &b2);
        if(a1 == 0 || a2 == 0)
		{
			sp(n - i);
			return;	
		} 
        ll y1 = 0, y2 = 0;
        ll d = Exgcd(a1, a2, y1, y2);
        if((b2 - b1) % d != 0)
		{
			sp(n - i);
			return;	
		} 
        ll cnt = a2 / d;
        y1 = (qmul(y1, ((b2 - b1) / d % a2 + a2) % a2, cnt) + cnt) % cnt;
        
        b1 = y1 * a1 + b1;
        a1 = (a1 * cnt);
        b1 = (b1 % a1 + a1) % a1;
    }

    ll ans = (b1 % a1 + a1) % a1;
    printf("%lld \n", ans);
}

int main()
{
    ll n = 0;
    
    while(cin >> n)
    {
    //	scanf("%lld", &n);
    	solve(n);
	}

    return 0;
}
