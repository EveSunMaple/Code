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

int main()
{
    ll a1, a2;
    ll b1, b2;
    ll n = 0;
    //freopen("1.txt","r",stdin);
    scanf("%lld", &n);
    scanf("%lld%lld", &a1, &b1);
    //printf("1:\nX = %lld (mod %lld)\n", b1, a1);
    for(ll i = 2; i <= n; i++)
    {
        scanf("%lld%lld", &a2, &b2);
        //printf("2:\nX = %lld (mod %lld)\n", b2, a2);
        ll y1 = 0, y2 = 0;
        //a1 * y1 - a2 * y2 = b2 - b1
        //y1 y2 dont know
        ll d = Exgcd(a1, a2, y1, y2);
        if((b2 - b1) % d != 0)
		{
			cout << -1;
			return 0;	
		} 
        ll cnt = a2 / d;
        //y1 = y1 / d;
        //y1 = (y1 % cnt + cnt) % cnt;
		//y1 = (y1 = y1 / d * (b2 - b1) % cnt + cnt) % cnt;
		//y1 = (qmul(b2 - b1, y1, cnt) + cnt) % cnt;
        y1 = (qmul(y1, ((b2 - b1) / d % a2 + a2) % a2, cnt) + cnt) % cnt;
        
        b1 = y1 * a1 + b1;
        a1 = a1 * cnt;
        b1 = (b1 % a1 + a1) % a1;
        //printf("AND:\nX = %lld (mod %lld)\n", b1, a1);
    }

    //printf("X = %lld k + %lld \n", a1, b1);

    ll ans = (b1 % a1 + a1) % a1;
    printf("%lld", ans);

    return 0;
}
