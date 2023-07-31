#include <iostream>
#include <cstring>
#include <cstdio>
#define N 1000005

using namespace std;

int n, ans;
int a[N];

void dfs(int crd, int deep, int val)
{
    if (deep <= 4)
    {
        for (int i = crd + 1; i <= n - (4 - deep); i++)
        {
        	//printf("IN->%d\n", i);
            dfs(i, deep + 1, val ^ a[i]); 
        }
    }
    else if (val == 0) ans++;
}

int main()
{
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
    }
    dfs(0, 1, 0);
    printf("%d", ans);
    return 0;
}
