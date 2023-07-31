#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#define N 1005

int a[N], b[N];
int quest[N][2];
int change[N][N];
bool tag[N];

int main()
{
    // 真的毫无头绪，我是fw呜呜呜
    freopen("chord.in", "r", stdin);
    freopen("chord.out", "w", stdout);
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n, m;
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
        for (int i = 1; i <= n; i++) scanf("%d", &b[i]);
        // int l = 1e9, r = 0;
        for (int i = 1; i <= m; i++)
        {
            int l, r;
            scanf("%d%d", &l, &r);
            quest[i][0] = l;
            quest[i][1] = r;
            for (int j = l; j <= r; j++)
            {
                tag[j] = true;
                change[i][b[j]]++;
                change[i][a[j]]--;
            }
        }
        for (int i = 1; i <= n; i++)
            if (!tag[i] && a[i] != b[i]) goto away;
        
        printf("TAK\n"); continue;
        away: printf("NIE\n");
    }
    return 0;
}