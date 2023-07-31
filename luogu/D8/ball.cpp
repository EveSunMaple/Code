#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <cmath>
#define mod 500009
#define N 1000005

using namespace std;

int cag[N]; // 有几种因数
bool no_prime[N];
int fin[2005];
int sum[2005];

void init(int n)
{
    memset(fin, 0, sizeof(fin));
    memset(sum, 0, sizeof(sum));
    memset(cag, 0, sizeof(cag));
    for (int i = 2; i <= n; i++)
    {
        if(!no_prime[i])
        {
            cag[i] = 2;
            for (int j = i + i; j <= n; j += i)
            {
                no_prime[j] = true;
            }
        }
        for (int j = 2; j <= i; j++)
        {
            //if (i > 1e3) break;
            long long aim = i * j;
            if (aim > n) { break; }
            if (j == i) cag[aim] = cag[j] + cag[i] - 1;
            else if (i % j) cag[aim] = cag[j] * cag[i]; 
            else cag[aim] = cag[j] * cag[i] - 2;
        }
    }
    for (int i = 1; i <= n; i++) //printf("\r%f\r", (float)i / n);
    {
        if (!sum[cag[i]]) sum[cag[i]] = 1;
        sum[cag[i]] = (sum[cag[i]] * (++fin[cag[i]])) % mod;
    }
}

int main()
{
    freopen("ball.in", "r", stdin);
    freopen("ball.out", "w", stdout);
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n, ans = 1;
        scanf("%d", &n);
        init(n);
        for (int i = 1; i <= 2000; i++)
            if (sum[i]) ans = (ans * sum[i]) % mod;
        printf("%d\n", ans);
    }
    return 0;
}