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
    node(){ val = 0, crd = 0; }
    node(int a, int b)
    { val = a, crd = b; }
};

bool cmp(node a, node b)
{
    if (a.val < b.val)
        return true;
    return false;
}

int n, m;
int l = 1e9, r = -1e9;
int old[N], ans = 0;
vector<node> a;
vector<int> goto_l;
vector<int> goto_r;

void Gol(int val, int li);
void Gor(int val, int li);

void Gol(int val, int li)
{
    int fix = r - val;
    li += fix;
    // printf("have: %d<%d>\n", li, fix);
    int gol = lower_bound(goto_l.begin(), goto_l.end(), li) - goto_l.begin();
    if (!binary_search(goto_l.begin(), goto_l.end(), li)) gol--;
    if (gol < 0) gol = 0;
    int aim = n - 1 - gol;
    li -= goto_l[gol];
    ans = a[aim].crd;
    // printf("gol : FIND : %d[%d]\n", aim, a[aim].val);
    if (val == a[aim].val) return;
    Gor(a[aim].val, li);
}

void Gor(int val, int li)
{
    int fix = val - l;
    li += fix;
    // printf("have: %d<%d>\n", li, fix);
    int gor = lower_bound(goto_r.begin(), goto_r.end(), li) - goto_r.begin();
    if (!binary_search(goto_r.begin(), goto_r.end(), li)) gor--;
    if (gor < 0) gor = 0;
    int aim = gor;
    li -= goto_r[gor];
    ans = a[aim].crd;
    // printf("gor : FIND : %d[%d]\n", aim, a[aim].val);
    if (val == a[aim].val) return;
    Gol(a[aim].val, li);
}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        int temp = 0;
        scanf("%d", &temp);
        a.push_back(node(temp, i));
        old[i] = temp;
        l = min(temp, l);
        r = max(temp, r);
    }
    int all = r - l;
    sort(a.begin(), a.end(), cmp);
    for (node n : a)
    {
        int temp = n.val - l;
        goto_l.push_back(all - temp);
        goto_r.push_back(temp);
    }
    sort(goto_l.begin(), goto_l.end());
    while (m--)
    {
        int ai, li;
        scanf("%d%d", &ai, &li);
        int stroad = r - old[ai];
        if (n == 1) goto out;
        if (stroad > li) Gor(old[ai], li);
        else
        {
            li -= stroad;
            int op = li / all;
            li %= all;
            if (op & 1) Gor(a[0].val, li);
            else Gol(a[n - 1].val, li);
        }
        printf("%d\n", ans);
        continue;
        out: printf("%d\n", old[1]);
    }
    return 0;
}