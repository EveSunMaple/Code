#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <cmath>
#include <queue>

using namespace std;

const int N = 3 * 1e5 + 1;
long long sum[N], a[N];

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        long long n;
        long long k = 0;
        long long ans = 0;
        long long front = 0;
        scanf("%lld", &n);
        for (int i = 1; i <= n; i++)
        {
            scanf("%lld", &a[i]);
            sum[i] = sum[i - 1] + a[i];
        }
        for (int i = 1; i <= n; i++)
        {
            front = max(front, sum[i]);
            if (ans < front + sum[n] - sum[i])
            {
                ans = front + sum[n] - sum[i];
                k = front;
            }
        }
        printf("%lld\n", k);
    }
    return 0;
}