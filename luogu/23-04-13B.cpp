#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#define ll long long

using namespace std;

ll map[5000][5000];
ll node[5000][5000];
ll lim[5000];
bool road[5000];
ll n, m, s, t;

ll solve(ll crd, bool road[5000])
{
    ll cnt = 0;
    ll ans = 1e9;
    for(ll i = 1; i <= lim[crd]; i++)
    {
        ll next_crd = node[crd][i];
        if(next_crd == s)
            return map[crd][next_crd];

        if(road[next_crd] == 0)
        {
            road[next_crd] = 1;
            ans = min(ans, solve(next_crd, road) + map[crd][next_crd]);
            cnt++;
        }
    }
    if(cnt == 0)
        return 1e9;
    return ans;
}

int main()
{
    scanf("%lld %lld %lld %lld", &n, &m, &s, &t);
    for(ll i = 1; i <= m; i++)
    {
        ll x, y;
        scanf("%lld %lld", &x, &y);
        scanf("%lld", &map[x][y]);
        map[y][x] = map[x][y];
        node[x][++lim[x]] = y;
        node[y][++lim[y]] = x;
    }

    road[t] = 1;
    cout << solve(t, road);

    return 0;
}