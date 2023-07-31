#include <iostream>
#include <cstring>
#include <cstdio>
#define fastio                   \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0)
#define pir pair<ll, ll>
#define ll long long

using namespace std;

inline ll gcd(ll a, ll b)
{
    return a == 0 ? b : gcd(b % a, a);
}

inline bool check(pir a, pir b)
{
    return a.first == b.first && a.second == b.second;
}

inline bool cmp(pir a, pir b) //if a > b
{
    ll num_a = a.first * b.second;
    ll num_b = b.first * a.second;
    return num_a > num_b;
}

inline pir calc(pir l, pir r)
{
    return make_pair(l.first + r.first, l.second + r.second);
}

// inline void init(pir &temp)
// {
//     int p = gcd(temp.first, temp.second);
//     temp.first /= p;
//     temp.second /= p;
// }

int main()
{
    fastio;
    freopen("enemy.in", "r", stdin);
    freopen("enemy.out", "w", stdout);
    ll a, b;
    scanf("%lld%lld", &a, &b);
    ll p = gcd(a, b);
    a /= p;
    b /= p;
    pir aim = make_pair(a, b);
    pir l = make_pair(0, 1);
    pir r = make_pair(1, 0);
    pir mid = calc(l, r);
    while (true)
    {
        pir mid = calc(l, r);
        if (check(aim, mid)) break;
        if (cmp(aim, mid)) // aim > mid
        {
            printf("R");
            l = mid;
        }
        else 
        {
            printf("L");
            r = mid;
        }
    }
    return 0;
}