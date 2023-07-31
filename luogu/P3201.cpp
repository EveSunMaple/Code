#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#define N 1000005

using namespace std;

vector<int> g[N];
int col[N], now[N];
int n, m, ans;

void solve(int x, int y)
{
    // x，y是操作的颜色，不是实际颜色
    for (int i : g[x]) // 在要变化的颜色点遍历
    {
        // 如果旁边是y，说明边界消失
        if (col[i - 1] == y) ans--;
        if (col[i + 1] == y) ans--;
    }
    // col[i]里面存的已经不是实际的颜色了
    // 要满足启发式合并的要求，col[i]与实际操作不符
    for (int i : g[x]) col[i] = y;
    for (int i : g[x]) g[y].push_back(i);
    g[x].clear();
    // 换句话说，g、col里面存的都是符合我们操作的元素
}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
    {  
        scanf("%d", &col[i]); // 记录i的颜色
        now[col[i]] = col[i]; // 记录颜色存在
        if (col[i] != col[i - 1]) ans++;
        g[col[i]].push_back(i); // 在这个颜色中添加i
    }
    while (m--)
    {
        int temp; scanf("%d", &temp);
        if (temp == 1)
        {
            int x, y;
            scanf("%d%d", &x, &y);
            if (x == y) continue;
            if (g[now[x]].size() > g[now[y]].size())
                swap(now[x], now[y]);
            // 因为我们要确保从小到大合并
            // 同时不能改变颜色影响后续操作
            // 我们x，y是实际的颜色用来判断
            // now[x]，now[y]是操作的颜色
            solve(now[x], now[y]);
        }
        else printf("%d\n", ans);
    }
    return 0;
}