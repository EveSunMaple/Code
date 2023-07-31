#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
#include <cstdio>
#include <cmath>
#define MAXN 500005

int n; // 序列长度
int a[MAXN]; // 原序列
int c[MAXN]; // 树状数组
long long ans; // 逆序对个数

using namespace std;

int lowbit(int i)
{
    return i & (-i);
}

// 单点修改
void add(int x, int k) 
{
    for (int i = x; i <= n; i += lowbit(i)) 
    {
        c[i] += k;
    }
}

// 区间查询
int query(int x) 
{
    int sum = 0;
    for (int i = x; i > 0; i -= lowbit(i)) 
    {
        sum += c[i];
    }
    return sum;
}

// 求逆序对个数
void solve() {
    // 离散化
    vector<int> v(a + 1, a + n + 1);
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    for (int i = 1; i <= n; i++)
    {
        a[i] = lower_bound(v.begin(), v.end(), a[i]) - v.begin() + 1;
    }

    // 求逆序对个数
    ans = 0;
    for (int i = n; i >= 1; i--) {
        ans += query(a[i] - 1);
        add(a[i], 1);
    }

    printf("%lld" , ans);
}

int main()
{
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) scanf("%d", &a[i]);

    solve();

    return 0;
}