#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#define N 200005

using namespace std;

int fa[N]; // father
int val[N];
int n, k;

int gcd(int m, int n)
{
    return n == 0 ? m : gcd(n, m % n);
}

int dfs(int crd, int w)
{
    int d = -1;
    int v = fa[crd];
    if(!v) return -1;
    if(gcd(w, val[v]) > 1) d = v;
    else d = dfs(v, w);
    return d;
}

int main()
{
    scanf("%d%d", &n, &k);
    for(int i = 1; i <= n; i++) scanf("%d", &val[i]);
    for(int i = 1; i < n; i++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        fa[v] = u;
    }
    for(int i = 1; i <= k; i++)
    {
        int u, crd;
        scanf("%d%d", &u, &crd);
        if(u == 1) printf("%d\n", dfs(crd, val[crd]));
        else 
        {
            int a;
            scanf("%d", &a);
            val[crd] = a;
        }
    }
    return 0;
}