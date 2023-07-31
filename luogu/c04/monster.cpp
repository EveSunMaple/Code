#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <queue>

using namespace std;

const int N = 1e5 + 5;
struct monster
{
    int d, v;
    monster(int x, int y)
    { d = x; v = y; }
    monster()
    { d = d; v = v; }
}val[N];

bool cmp(monster a, monster b)
{
    if (a.d < b.d) return true;
    else if (a.d == b.d) return a.v > b.v;
    return false;
}

void solve()
{
    int n, m, ans = 0;
    scanf("%d%d", &n, &m);
    priority_queue<int> att;
    for (int i = 1; i <= n; i++) 
    {
        int temp;
        scanf("%d", &temp);
        att.push(-temp);
    }
    for (int i = 1; i <= m; i++) scanf("%d", &val[i].d);
    for (int i = 1; i <= m; i++) scanf("%d", &val[i].v);
    sort(val + 1, val + 1 + m, cmp);
    int crd = 1;
    while (!att.empty() && crd < m)
    {
        int temp = -att.top();
        att.pop();
        int ret = 1e9;
        int ins = 0;
        while (crd < m)
        {
            if (val[crd].d < temp && val[crd].v > ins)
            {
                ret = crd;
                ins = val[crd].v;
            }
            if (val[crd].d >= temp) break;
            crd++;
        }
        crd = min(ret, crd);
        ans += ins;
    }
    printf("%d\n", ans);
}

int main()
{
    //freopen("monster.in", "r", stdin);
    //freopen("monster.out", "w", stdout);
    int n;
    scanf("%d", &n);
    while (n--) solve();
    return 0;
}