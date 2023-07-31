#include <iostream>
#include <cmath>
#define ll long long

using namespace std;

ll D = 0;

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

void add(ll &a1, ll a2, ll &b1, ll b2)
{
    ll y1 = 0, y2 = 0;
		
    ll d = Exgcd(a1, a2, y1, y2);
    if((b2 - b1) % d != 0)
	{
		//cout << -1;
		return;	
	} 
	ll cnt = a2 / d;
    y1 = (qmul(y1, ((b2 - b1) / d % a2 + a2) % a2, cnt) + cnt) % cnt;
        
    b1 = y1 * a1 + b1;
    a1 = (a1 * cnt);
    b1 = (b1 % a1 + a1) % a1;
    if(b1 <= D)
    {
  		ll num = (D - b1) / a1 + 1;
   		b1 += num * a1;
	}
    return;
}

int main()
{
    for(ll t = 1; ; t++)
    {
    	ll a = 0, b = 0;
		ll p = 0, e = 0, i = 0;
		scanf("%lld %lld %lld %lld", &p, &e, &i, &D);
		if(p == -1 && e == -1 && i == -1 && D == -1)
			return 0;
		a = 23; b = p;
		add(a, 28, b, e);
		add(a, 33, b, i);
		
		printf("Case %lld: the next triple peak occurs in %lld days. \n", t, (b - D));
    }

    return 0;
}