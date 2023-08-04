#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#define mod 5557
#define ll long long
#define fastio                   \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0)

using namespace std;

ll map[55][55];
ll now[55][55];
ll mul[55][55];
ll tmp[55][55];
ll tag[55];

struct Shop
{
    ll fa;
    ll u, v;
    Shop() { fa = 0; u = 0; v = 0; }
    Shop(ll a, ll b, ll c)
    { fa = a; u = b; v = c; }
};
// vector<ll> B;
// vector<ll> J;
// vector<ll> M;
// vector<ll> P;
vector<Shop> shop[4];
// vector<ll> no_1;
// vector<ll> no_2;
// vector<ll> no_3;
vector<ll> no[5];
// B J M P -> 1 1 1 1 -> 16
//{0 1 2 3}
ll n, m;

void init()
{
    for (ll i = 1; i <= n + n; i++)
        for (ll j = 1; j <= n + n; j++)
            now[i][j] = map[i][j];
}

ll solve()
{
    for (ll i = 1; i <= n + n; ++i)
    {
        for (ll j = 1; j <= n + n; ++j)
        {
            tmp[i][j] = 0;
            // printf("%d ", mul[i][j]);
        }
        // printf("\n");
    }
    // printf("\n");
    for (ll i = 1; i <= n + n; i++)
        for (ll j = 1; j <= n + n; j++)
            for (ll k = 1; k <= n + n; k++)
            {
                tmp[i][j] = (tmp[i][j] + (mul[i][k] * now[k][j] % mod)) % mod;
            }
    for (ll i = 1; i <= n + n; ++i)
    {
        for (ll j = 1; j <= n + n; ++j)
        {
            mul[i][j] = tmp[i][j];
        }
    }
    return mul[1][1];
}

int main()
{
    fastio;
    // freopen("c.in", "r", stdin);
    // freopen("c.out", "w", stdout);
    // scanf("%d%d", &n, &m);
    cin >> n >> m;
    for (ll i = 1; i <= m; i++)
    {
        ll u, v;
        string val;
        // scanf("%d%d", &u, &v);
        cin >> u >> v;
        cin >> val;
        for (unsigned ll j = 0; j < val.length(); j++)
        {
            if (val[j] == 'B') { shop[0].push_back(Shop(u + n, u, v)); } // tag[i] += 1 << 3; 
            if (val[j] == 'J') { shop[1].push_back(Shop(u + n, u, v)); } // tag[i] += 1 << 2; 
            if (val[j] == 'M') { shop[2].push_back(Shop(u + n, u, v)); } // tag[i] += 1 << 1; 
            if (val[j] == 'P') { shop[3].push_back(Shop(u + n, u, v)); } // tag[i] += 1;
        }
        map[u][u + n] = 1;
        map[u + n][v] = 1;
        map[u][v] = 1; 
    }
    ll t;
    // scanf("%d", &t);
    cin >> t;
    for (ll i = 0; i <= 15; i++)
    {
        init();
        ll op = 0;
        for (ll j = 0; j <= 3; j++)
        {
            if ((i >> j) & 1)
            {
                op++;
                for (Shop node : shop[j])
                {
                    now[node.u][node.fa] = 0;
                    now[node.fa][node.v] = 0;
                }
            }
        }
        for (int i = 1; i <= n + n; ++i)
        {
            for (int j = 1; j <= n + n; ++j)
            {
                mul[i][j] = 0;
            }
        }
        for (int i = 1; i <= n + n; i++)
        {
            mul[i][i] = 1;
        }
        ll ans = 0;
        for (ll i = 1; i <= t; i++)
            ans = (ans + solve()) % mod;
        no[op].push_back(ans);
    }
    ll ans = no[0][0];
    for (ll t : no[1]) { /*printf("cnt:1 : %lld \n", t);*/ ans = (mod + ans - t) % mod; }
    for (ll t : no[2]) { /*printf("cnt:2 : %lld \n", t);*/ ans = (ans + t) % mod; }
    for (ll t : no[3]) { /*printf("cnt:3 : %lld \n", t);*/ ans = (mod + ans - t) % mod; }
	ans = (ans + no[4][0]) % mod;
	// for (ll t : no[4]) ans = (ans + t) % mod;
    // printf("%d", ans);
    // cerr << ans;
    cout << ans << endl;
    return 0;
}