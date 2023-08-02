#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#define N 100005

using namespace std;

struct node
{
    int val, crd;
    node(){val = 0, crd = 0;}
    node(int a, int b)
    { val = a, crd = b; }
};

int ans;
int n, m, l = 1e9, r = -1e9;
int other[N];
vector<node> a;
vector<int> gol;
vector<int> gor;
int findhelp[N];

bool cmp(node a, node b)
{
    if (a.val < b.val)
        return true;
    return false;
}
void dfsl(int u, int li, bool way);

void dfsr(int u, int li, bool way)
{
    if (way) li += a[u].val - l;
    else li += u - l;
    // printf("have: %d<%d>\n", li, a[u].val - l);
    int temp = lower_bound(gor.begin(), gor.end(), li) - gor.begin();
    if (!binary_search(gor.begin(), gor.end(), li)) temp--;
    // printf("gor : FIND : %d[%d]\n", temp, a[temp].val);
    li -= gor[temp];
    if (temp - u == 0)
    {
        ans = a[temp].crd;
        return;
    }
    dfsl(temp, li, true);
}

void dfsl(int u, int li, bool way)
{
    if (way) li += r - a[u].val;
    // printf("have: %d\n", li);
    int temp = lower_bound(gol.begin(), gol.end(), li) - gol.begin();
    if (!binary_search(gol.begin(), gol.end(), li)) temp--;
    // printf("gol : FIND : %d<%d>\n", temp, gol[temp]);
    li -= gol[temp];
    temp = n - temp - 1;
    if (temp - u == 0)
    {
        ans = a[temp].crd;
        return;
    }
    // printf("gol : FIND : %d[%d]\n", temp, a[temp].val);
    ans = a[temp].crd;
    dfsr(temp, li, true);
}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        int temp;
        scanf("%d", &temp);
        a.push_back(node(temp, i));
        other[i] = temp;
        l = min(l, temp);
        r = max(r, temp);
    }
    sort(a.begin(), a.end(), cmp);
    int all = r - l;
    // int fix = l;
    for (int i = 0; i < n; i++)
    {
        // int temp = lower_bound(a.begin(), a.end(), fix) - a.begin();
        gor.push_back(a[i].val - l);
        gol.push_back(all - gor[gor.size() - 1]);
        // findhelp[i] = temp;
    }
    sort(gor.begin(), gor.end());
    sort(gol.begin(), gol.end());
    // for (int i = 1; i <= n; i++)
    //     printf("%d ", findhelp[i]);
    for (int i = 1; i <= m; i++)
    {
        int ai, li;
        scanf("%d%d", &ai, &li);
        int stroad = r - other[ai];
        if (stroad <= li)
        {
            li -= stroad;
            int op = li / all;
            li %= all;
            if (op & 1)
            {
                dfsr(0, li, true);
            }
            else
            {
                dfsl(n - 1, li, true);
            }
        }
        else
        {
            dfsr(other[ai], li, false);
        }
        printf("%d\n", ans);
    }
    return 0;
}