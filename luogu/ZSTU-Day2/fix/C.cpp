#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#define N 100005
#define ll long long 

using namespace std;

struct node
{
    ll val, crd;
    node(){ val = 0, crd = 0; }
    node(ll a, ll b)
    { val = a, crd = b; }
};

bool cmp(node a, node b)
{
    if (a.val < b.val)
        return true;
    return false;
}

ll n, m;
ll l = 1e9, r = -1e9;
ll old[N], ans = 0;
vector<node> a;
vector<ll> goto_l;
vector<ll> goto_r;

void Gol(ll val, ll li);
void Gor(ll val, ll li);

void Gol(ll val, ll li)
{
    ll fix = r - val;
    li += fix;
    // printf("have: %lld<%lld>\n", li, fix);
    ll gol = lower_bound(goto_l.begin(), goto_l.end(), li) - goto_l.begin();
    if (!binary_search(goto_l.begin(), goto_l.end(), li)) gol--;
    if (gol < 0) gol = 0;
    ll aim = n - 1 - gol;
    li -= goto_l[gol];
    ans = a[aim].crd;
    // printf("gol : FIND : %lld[%lld]\n", aim, a[aim].val);
    if (val == a[aim].val) return;
    ll change = goto_l[gol] - fix;
    ll op = li / change;
    li %= change;
    if (op & 1) Gol(val, li);
    else Gor(a[aim].val, li);
}

void Gor(ll val, ll li)
{
    ll fix = val - l;
    li += fix;
    // printf("have: %lld<%lld>\n", li, fix);
    ll gor = lower_bound(goto_r.begin(), goto_r.end(), li) - goto_r.begin();
    if (!binary_search(goto_r.begin(), goto_r.end(), li)) gor--;
    if (gor < 0) gor = 0;
    ll aim = gor;
    li -= goto_r[gor];
    ans = a[aim].crd;
    // printf("gor : FIND : %lld[%lld]\n", aim, a[aim].val);
    if (val == a[aim].val) return;
    ll change = goto_r[gor] - fix;
    ll op = li / change;
    li %= change;
    if (op & 1) Gor(val, li);
    else Gol(a[aim].val, li);
}

int main()
{
    scanf("%lld%lld", &n, &m);
    for (ll i = 1; i <= n; i++)
    {
        ll temp = 0;
        scanf("%lld", &temp);
        a.push_back(node(temp, i));
        old[i] = temp;
        l = min(temp, l);
        r = max(temp, r);
    }
    ll all = r - l;
    sort(a.begin(), a.end(), cmp);
    for (node n : a)
    {
        ll temp = n.val - l;
        goto_l.push_back(all - temp);
        goto_r.push_back(temp);
    }
    sort(goto_l.begin(), goto_l.end());
    while (m--)
    {
        ll ai, li;
        scanf("%lld%lld", &ai, &li);
        ll stroad = r - old[ai];
        if (n == 1) goto out;
        if (stroad > li) Gor(old[ai], li);
        else
        {
            li -= stroad;
            ll op = li / all;
            li %= all;
            if (op & 1) Gor(a[0].val, li);
            else Gol(a[n - 1].val, li);
        }
        printf("%lld\n", ans);
        continue;
        out: printf("1\n");
    }
    return 0;
}
