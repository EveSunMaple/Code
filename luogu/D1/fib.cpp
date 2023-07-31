#include <iostream>
#include <cstring>
#include <cstdio>
#define N 105

using namespace std;

long long v[N];
long long num[N * 100];
long long sum[N];
long long lim[N];
long long far;
long long ans;

int init(int n)
{
    long long w = 1;
    long long a = 1, b = 1;
    int i = 1;
    n -= w;
    for (i = 1; i <= 100; i++)
    {
        w = b * (i + 1);
        if (n >= 0) { far = n; n -= w; }
        else break;
        long long c = b;
        b = a + b;
        a = c;
    }
    return i;
}

int main()
{
    freopen("fib.in", "r", stdin);
    freopen("fib.out", "w", stdout);
    long long n; 
    scanf("%lld", &n);
    v[1] = v[2] = 1;
    sum[1] = 1; lim[1] = 1;
    num[1] = 1; num[2] = 1;
    long long a = 1, b = 1;
    long long w = 2;
    for (int i = 2; i < 100; i++)
    {
        w += b;
        long long c = b;
        b = a + b;
        a = c;
        lim[i] = b; //printf("lim[%d] = %lld\n", i, lim[i]);
        v[i + 1] = b;
        sum[i] = v[i] + sum[i - 1];
        if (w < N * 50 && w > 0) num[w] = 1; //printf("num[%d] = %lld\n", w, num[w]);
        int temp = 1;
        int strt = 0;
        for (int j = 1; j < i; j++)
        {
            v[i + 1] += v[j];
            if (w < N * 50 && w > 0)
            {
                for (int t = 1; t <= lim[j]; t++)
                {
                    num[w + temp] = num[strt + t] + 1;
                    //printf("num[%d] = num[%d] + 1 = %lld\n", w + temp, strt + t, num[w + temp]);
                    temp++;
                }
                strt += lim[j];
            }
        }
        //cout << sum[i] << endl;
    }
    int sit = init(n);
    //cout << sit << endl << far;
    if (far)
    {
        ans += sum[sit - 1];
        int temp = far / sit;
        int limt = far - temp * sit;
        ans += temp;
        for (int j = 1; j < temp; j++)
        {
            ans += num[j];
        }
        if (limt)
        {
            ans++; // i cannot do this
        }
        printf("%lld", ans);
    }
    else printf("%lld", sum[sit - 1]);
    return 0;
}