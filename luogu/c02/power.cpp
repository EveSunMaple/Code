#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <cmath>
#define N 100005

using namespace std;

struct power
{
    int a, b, c;
    power(int x, int y, int z)
    { a = x; b = y; c = z;}
    power()
    { a = a; b = b; c = c;}
}player[N];

bool tag[N];
bool cmp(power u, power v)
{
    if ((u.a > v.a) && (u.b > v.b || u.b > v.c || u.c > v.b || u.c > v.c)) return true;
    if ((u.b > v.b) && (u.a > v.a || u.a > v.c || u.c > v.a || u.c > v.c)) return true;
    if ((u.c > v.c) && (u.b > v.b || u.b > v.a || u.a > v.b || u.a > v.a)) return true;
    if (u.a > u.b && u.b > u.a) return true;
    if (u.c > u.b && u.b > u.c) return true;
    if (u.a > u.c && u.c > u.a) return true;
    return false;
}

void solve()
{
    int n, tot = 0, ans = 0;
    scanf("%d", &n);
    while (n--)
    {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        player[++tot] = power(a, b, c);
        tag[tot] = true;
        for (int i = 1; i < tot; i++)
        {
            bool win = cmp(player[tot], player[i]), fal = cmp(player[i], player[tot]);
            // if (tag[i]) 
            // {
            //     printf("[%d] > [%d] - %d\n", tot, i, win);
            //     if (win && !fal) { tag[i] = false; ans--; }
            // }
            // if (tag[tot]) 
            // {
            //     printf("[%d] > [%d] - %d\n", i, tot, fal);
            //     if (fal && !win) { tag[tot] = false; ans--; }
            // }       
            if (!fal) tag[i] = false;
            if (!win) tag[tot] = false;
        } 
    }
    for (int i = 1; i <= tot; i++) if(tag[i]) ans++;
    printf("%d\n", ans);
}

int main()
{
    freopen("power.in", "r", stdin);
    freopen("power.out", "w", stdout);
    int n;
    scanf("%d", &n);
    while (n--) solve();
    return 0;
}