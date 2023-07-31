#include <iostream>
#include <cstring>
#include <cstdio>
#define N 105

using namespace std;

long long v[N];   // 每一段的和
long long sum[N]; // 总合
long long num[N]; // 每一段的个数
long long far;
long long ans;

// n当前的num长度 ，temp当前有多少个完整的num
long long fsum(int n, long long temp)
{                  // 定义一个函数fsum，用来计算数列的一段和
    if (!temp)     // 如果已经没有完整的fib
        return 0;  // 如果temp为0，返回0
    if (temp == 1)
        return 1;  // 如果temp为1，返回1
    if (temp < num[n - 1])
    {                             // 如果temp小于fib[n-1]
        return fsum(n - 1, temp); // 递归调用fsum(n-1,temp)
    }
    else
    {                                                 // 否则
        temp -= num[n - 1];                           // 更新temp的值
        return sum[n - 1] + temp + fsum(n - 2, temp); // 返回sum[n-1]+temp+fsum(n-2,temp)
    }
}

int fn(int r, int n, long long temp)
{ // 定义一个函数fn，用来计算数列的剩余部分和
    if (r <= 0)
        return 0;                                                                                // 如果r小于等于0，返回0
    return temp < num[n + 1] ? fn(r - 1, n - 1, temp) : 1 + fn(r - 2, n - 2, temp - num[n + 1]); // 如果temp小于fib[n+1]，返回fn(r-1,n-1,temp)，否则返回1+fn(r-2,n-2,temp-fib[n+1])
}

int init(int n)
{
    long long w = 1;
    long long a = 1, b = 1;
    int i = 1;
    n -= w;
    for (i = 1; i <= 100; i++)
    {
        w = b * (i + 1);
        if (n >= 0)
        {
            far = n;
            n -= w;
        }
        else
            break;
        long long c = b;
        b = a + b;
        a = c;
    }
    return i;
}

int main()
{
    //freopen("fib.in", "r", stdin);
    //freopen("fib.out", "w", stdout);
    long long n;
    scanf("%lld", &n);
    v[1] = v[2] = 1;
    sum[1] = 1;
    num[1] = 1;
    num[2] = 1;
    long long a = 1, b = 1;
    long long w = 2;
    for (int i = 2; i < 100; i++)
    {
        long long c = b;
        b = a + b;
        a = c;
        v[i + 1] = b;
        num[i + 1] = b;
        sum[i] = v[i] + sum[i - 1];
        for (int j = 1; j < i; j++)
        {
            v[i + 1] += v[j];
        }
        // cout << sum[i] << endl;
    }
    int sit = init(n);
    if (far)
    {
        ans += sum[sit - 1];
        long long temp = far / sit;  // 有几个完整的fib
        int limt = far - temp * sit; // 不完整的fib
        ans += temp;
        ans += fsum(sit, temp);
        ans += fn(limt, sit, temp + num[sit + 1]);
        printf("%lld", ans);
    }
    else
        printf("%lld", sum[sit - 1]);
    return 0;
}