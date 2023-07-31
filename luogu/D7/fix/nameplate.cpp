#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cctype>
#include <vector>
#define fastio                   \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0)
#define ll long long
#define N 100005

using namespace std;

int n, D;
int a[N];
int lc[N], rc[N];
int stk[N], top;
vector<int> bac[1 << 20];
ll ans;

void solve(int w, int l, int r)
{
    // 使用 lower_bound 函数
    // bac[v] 数组存储了权值为 v 的元素出现的全部位置
    // 因为我们的式子其实是 a[i] ^ a[w] ^ Z ^ D = 0;
    // 那么我们知道了 D ^ a[i] ^ a[w] = v，只有 Z = v 时成立
    // 那么我们就要去找这一区间的剩下来的部分中有几个 Z 符合要求
    // 那么在 bac[v] 数组中查找权值为 v 的元素的第一个大于等于 r+1 或者第一个大于等于 w+1 的下标的地址
    // 并计算出两次查找的结果之差，就可以快速计算出权值为 v 的元素在这一个区间内出现了多少次
    // 最后累加到答案中，递归分开的小区间
    if (w - l < r - w) // 从较短的区间枚举
    {
        for (int i = l; i <= w; i++)
        {
            int v = D ^ a[i] ^ a[w];
            ans += lower_bound(bac[v].begin(), bac[v].end(), r + 1) - lower_bound(bac[v].begin(), bac[v].end(), w);
        }
    }
    else
    {
        for (int i = w; i <= r; i++)
        {
            int v = D ^ a[i] ^ a[w];
            ans += lower_bound(bac[v].begin(), bac[v].end(), w + 1) - lower_bound(bac[v].begin(), bac[v].end(), l);
        }
    }
    if (lc[w]) // 如果左边区间还存在最小值
        solve(lc[w], l, w - 1);
    if (rc[w]) // 如果右边区间还存在最小值
        solve(rc[w], w + 1, r);
}

int main()
{
    fastio;
    freopen("nameplate.in", "r", stdin);
    freopen("nameplate.out", "w", stdout);
    scanf("%d%d", &n, &D);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
        bac[a[i]].push_back(i);
        if (!top || a[i] >= a[stk[top]]) // 如果栈为空或者输入的大于等于栈顶
            stk[++top] = i;              // 记录下标
        else                             // 否则说明此时输入的是一个更小的数
        {
            for (; top && a[i] < a[stk[top]]; --top)
                rc[stk[top - 1]] = stk[top]; // 记录 top - 1 右边大于等于且最小它的数
            lc[i] = stk[top + 1];            // 记录当前输入数字左边大于等于它且最小的数
            stk[++top] = i;                  // 此时输入的数大于等于栈顶，重新插入
        }
    }
    for (; top; --top)
        rc[stk[top - 1]] = stk[top]; // 不断取出更新

    // rc[0] 表示整个序列中第一个不小于 0 的元素的下标，也就是整个序列中最小元素的下标
    solve(rc[0], 1, n); // 获得 1~n 之间最小值的下标
    printf("%lld", ans);
    return 0;
}
