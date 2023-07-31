#include <iostream>
#include <cmath>
#include <cstdio>
#define ll long long
#define INF 10000005

using namespace std;

ll bag[2][INF];
ll t[INF], v[INF];
ll Time = 0, sp = 0;

int main()
{
    ll ans = 0;
    scanf("%lld %lld", &Time, &sp);
    for(int i = 1; i <= sp; i++) 
        {scanf("%lld %lld", &t[i], &v[i]);}
    for(int i = 1; i <= sp; i++)
    {
        for(int j = 0; j <= Time; j++)
        {
            bag[i & 1][j] = bag[(i + 1) & 1][j];
            if(j >= t[i])
            {
                bag[i & 1][j] = max(bag[(i + 1) & 1][j], bag[i & 1][j - t[i]] + v[i]);
                ans = max(ans, bag[i & 1][j]);
            }
        }
    }

    printf("%lld", ans);

    return 0;
}