#include <iostream>
#include <cstring>
#include <cstdio>
#define N 200005

using namespace std;

int mid[4][5] = {{0, 2, 6, 14, 20},
                 {0, 4, 12, 18, 20},
                 {0, 8, 14, 16, 20},
                 {0, 6, 8, 12, 20}};
int ran[10]; 

long long calc(int l, int i, long long s, long long k) 
{
    // W = (s + 20 * x + mid_i) * (k - 4 * x - i)
    // W = - 80x^2 - 4(s + mid_i)x + 20(k - i)x + ......
    // ans = 20(k - i) - 4(s + mid_i) / 160;
    if (k == 0) return 0;
    long long t = (20 * (k - i) / 160) - (4 * (s + mid[l][i]) / 160);
    long long ans = 0;
    for (int x = t - 10; x <= t + 10; x++)
    {
        if (x * 4 + i >= k || x < 0) continue;
        long long a = (s + 20ll * x + mid[l][i]);
        long long b = (k - 4ll * x - i);
        //printf("NOW : \nX : %d\nI : %d\n ADD : %d\nA[%lld] * B[%lld]\nSUM : %lld\n", x, i, mid[l][i], a, b, a * b);
        ans = max(ans, a * b);
    }
    return ans;
}

int main()
{
    int t;
    scanf("%d", &t);
    ran[2] = 0;
    ran[4] = 1;
    ran[8] = 2;
    ran[6] = 3;
    while (t--)
    {
        long long s, k;
        scanf("%lld%lld", &s, &k);
        if (s % 10 == 0) printf("%lld\n", s * k);
        else if (s % 10 == 5) printf("%lld\n", max(s * k, (s + 5) * (k - 1)));
        else 
        {
            long long ans = s * k;
            if (s % 10 == 1
             || s % 10 == 3
             || s % 10 == 7
             || s % 10 == 9)
            {
                ans = max(ans, (s + s % 10) * (k - 1));
                for (int i = 0; i < 4; i++)
                {
                    long long now = ((s % 10) * 2) % 10;
                    ans = max(ans, calc(ran[now], (i + ran[now]) % 4, s + s % 10, k - 1));
                    ans = max(ans, (s + s % 10 + mid[ran[now]][i]) * (k - i - 1));
                }
            }
            else
            {
                for (int i = 0; i < 4; i++)
                {
                    ans = max(ans, calc(ran[s % 10], (i + ran[s % 10]) % 4, s, k));
                    ans = max(ans, (s + mid[ran[s % 10]][i]) * (k - i));
                }
            }
            printf("%lld\n", ans);
        }
    }
    return 0;
}