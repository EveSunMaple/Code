#include <iostream>
#include <cstring>
#include <cstdio>
#define N 2250005
#define mod 500009
#define ll long long

using namespace std;

bool not_prime[N];
int prime[N], tot;
ll calc[N], cnt[N], ans[N];
int main()
{
    //freopen("ball.in", "r", stdin);
    //freopen("ball.out", "w", stdout);
    // init
    ans[0] = ans[1] = 1;
    for (int i = 1; i < N; i++) calc[i] = 1;
    for (int i = 2; i <= N - 1; i++)
    {
        if (!not_prime[i])
            prime[++tot] = i;
        for (int j = 1; j <= N - 1 && i * prime[j] <= N - 1; j++)
        {
            not_prime[i * prime[j]] = true;
            if (i % prime[j] == 0)
                break;
        }
    }
    // calc
    for (int i = 1; i <= tot; i++)
    {
        for (int j = prime[i]; j < N; j += prime[i])
        {
            ll temp = j, time = 0;
            while (temp % prime[i] == 0)
            {
                temp /= prime[i];
                time++;
            }
            calc[j] = calc[j] * (time + 1) % mod;
        }
    }
    // ans
    for (int i = 2; i < N; i++)
    {
        ans[i] = (ans[i - 1]) * (++cnt[calc[i]]) % mod;
    }

    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n;
        scanf("%d", &n);
        if (n >= 2250000) printf("0\n");
        else printf("%lld\n", ans[n]);
    }

    return 0;
}