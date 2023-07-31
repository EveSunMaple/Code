#include <iostream>
#include <cstdio>
#define ll long long

using namespace std;

ll c1, c2, c3, c4, n;

int main()
{
    scanf("%lld %lld %lld %lld %lld", &c1, &c2, &c3, &c4, &n);

    for(int i = 1; i <= n; i++)
    {
        ll n1, n2, n3, n4, sum;
        scanf("%lld %lld %lld %lld %lld", &n1, &n2, &n3, &n4, &sum);

        for(int j = 0; j < (1 << n1 + n2 + n3 + n4); j++)
        {
            ll sub = 0;
            for(int t = 0; t < n1 + n2 + n3 + n4; t++)
            {
                if((j >> t) & 1)
                {
                    if(t < n1)
                    {
                        sub += c1;
                    }
                }
            }
        }
    }

    return 0;
}