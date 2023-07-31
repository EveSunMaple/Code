#include <iostream>
#include <cstring>
#include <vector>
#include <cstdio>
#include <cmath>
#define N 100005

using namespace std;

vector<vector<__int128 > > g(N);
pair<__int128, __int128> val[N];
__int128 indeg[N], outdeg[N];
__int128 n, m;

inline __int128 read()
{
    __int128 x = 0, f = 1;
    char ch = getchar();
    while(ch < '0' || ch > '9')
    {
        if(ch == '-')
            f = -1;
        ch = getchar();
    }
    while(ch >= '0' && ch <= '9'){
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    return x * f;
}

inline void print(__int128 x)
{
    if(x < 0)
    {
        putchar('-');
        x = -x;
    }
    if(x > 9)
        print(x / 10);
    putchar(x % 10 + '0');
}

__int128 gcd(__int128 a, __int128 b)
{
    if (b == 0)  return a;
    __int128 d = gcd(b, a % b);
    return d;
}

pair<__int128, __int128> calc(pair<__int128, __int128> a, __int128 b)
{
	a.second *= b;
	__int128 d = gcd(a.first, a.second);
	a.first /= d;
	a.second /= d;
	return a;
}

pair<__int128, __int128> add(pair<__int128, __int128> a, pair<__int128, __int128> b)
{
	if(b.first == 0 && b.second == 0)
		return a;
	a.first *= b.second;
	b.first *= a.second;
	//a.second *= b.second;
	//b.second *= temp;
	__int128 p = a.first + b.first;
	__int128 q = a.second * b.second;
	__int128 d = gcd(p, q);
	p /= d;
	q /= d;
	return make_pair(p, q);
}

void dfs(__int128 u, __int128 from, pair<__int128, __int128> w)
{
	if(!g[u].size()) return;
	w = calc(w, g[u].size());
	//printf("node:%d val:%d|%d w:%d|%d\n", u, val[u].first, val[u].second, w.first, w.second);
	for(__int128 i = 0; i < g[u].size(); i++)
	{
		__int128 v = g[u][i];
		if(v == from) continue;
		val[v] = add(w, val[v]);
		dfs(v, u, w);
	}
}

int main()
{
	//freopen("water.in", "r", stdin);
	//freopen("water.out", "w", stdout);
	//scanf("%d%d", &n, &m);
    n = read();
    m = read();
	for(__int128 i = 1; i <= n; i++)
	{
		__int128 t;
		t = read();
		while(t--)
		{
			__int128 v;
            v = read();
			g[i].push_back(v);
			indeg[v]++; outdeg[i]++;
		}
	}
	for(__int128 i = 1; i <= m; i++)
	{
		val[i] = add(make_pair((__int128)1, (__int128)1), val[i]);
		dfs(i, 0, val[i]);
	}
	for(__int128 i = 1; i <= n; i++)
		if(!outdeg[i]) { print(val[i].first); printf(" "); print(val[i].second); printf("\n"); }
	return 0;
}