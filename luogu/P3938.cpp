#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>

using namespace std;

//数i的父节点等于x - f[i];
long long f[100];

void find(long long a, long long b)
{
    if(a < b) swap(a, b); //如果 a 小于 b 交换
    if(a == b) {printf("%lld\n", a); return; }
    //因为 lower_bound 返回的是指针所以我们减去f就是下标
    //找到第一个比 a 大的 f[i] , a - f[i - 1] 其实就是它的父亲结点
    int crd = lower_bound(f, f + 62, a) - f - 1; 
    find(b, a - f[crd]); //把 a 跳到它的父节点
}

int main()
{
    f[0] = 1; f[1] = 1;
    //生成逼近上限的斐波那契数列，用来获取父节点
    for(int i = 2; i <= 61; i++)f[i] = f[i-1] + f[i-2];
    
    int m; scanf("%d", &m);
    for(int i = 1; i <= m; i++)
    {
        long long a, b;
        scanf("%lld%lld", &a, &b);
        find(a, b);
    }

    return 0;
}