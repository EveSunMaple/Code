#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#define fastio                   \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0)
#define ll long long
#define N 100005

using namespace std;

string num;
int p, ans;

bool divis(int l, int r)
{
    int val = num[r] - '0';
    int mul = 0;
    for (int i = r - 1; i >= l; i--, mul++)
    {
        int temp = 10;
        for (int j = 1; j <= mul; j++) temp *= 10;
        val += temp * (num[i] - '0');
    }
    //printf("val(%d,%d)[%d]\n", l, r, val);
    return !(val % p);
}

void solve(int l, int r, int t, bool from, bool time)
{
    if (!t) 
    {
        bool my = divis(l, r);  
        if ((from || my) && time) 
        {
            //printf("OK! => ");
            ans++;
        }
        //printf("(%d,%d)[%d]\n", l, r, my);
        return;
    }

    for (int i = l; i <= r - t; i++)
    {
        bool temp = time;
        bool my = divis(l, i);
        if (!from && !my) temp = false;
        //printf("(%d,%d)[%d]|(%d,%d)\n", l, i, my, i + 1, r);
        solve(i + 1, r, t - 1, my, temp);
    }
}

int main()
{
    freopen("division.in", "r", stdin);
    freopen("division.out", "w", stdout);
    fastio;
    int len = 1;
    for (; ; len++)
    {
        char temp = getchar();
        if (temp <= '9' && temp >= '0')
            num[len] = temp;
        else break;
    }
    len--;
    scanf("%d", &p);
    for (int i = 1; i < len; i++)
        solve(1, len, i, true, true);
    ans++;
    printf("%d", ans);
    return 0;
}