#include <iostream>
#include <cstring>
#include <cstdio>
#define ll long long

using namespace std;

ll Kill[20];

ll gcd(ll a, ll b)
{
    return b == 0 ? a : gcd(b, a % b);
}

ll lcm(ll a, ll b)
{
    return a * b / gcd(a, b);
}

int main()
{
    ll n = 0;
    scanf("%lld", &n);

    for(int i = 1; i <= n; i++)
    {
        ll N, M, ans = 0;
        scanf("%lld %lld", &N, &M);

        memset(Kill, 0, sizeof(Kill));

        for(int j = 0; j < M; j++)
        {
            scanf("%lld", &Kill[j]);
        }

        for(int j = 0; j < (1 << M); j++)
        {
            ll num = 1, cnt = 0;
            for(int t = 0; t < M; t++)
            {
                if((j >> t) & 1)
                {
                    num = lcm(num, Kill[t]);
                    cnt++;
                }
            }

            if(cnt & 1) {ans -= N / num; }
            else {ans += N/ num; }
        }

        printf("Case %d: %lld\n", i, ans);
    }
    
    return 0;
}