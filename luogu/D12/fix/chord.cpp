#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <queue>
#define N 1005

using namespace std;

struct chord
{
    int num, des;
}a[N];

int b[N];
queue<int> que[N];
pair<int, int> quest[N];

bool cmp(chord a, chord b)
{
    return a.des < b.des;
}

int main()
{
	freopen("chord.in","r",stdin);
	freopen("chord.out","w",stdout);
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n, m;
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= n; i++) 
        {
            scanf("%d", &a[i].num);
            que[a[i].num].push(i);
        }
        for (int i = 1; i <= n; i++) scanf("%d", &b[i]);
        for (int i = 1; i <= m; i++) scanf("%d%d", &quest[i].first, &quest[i].second);
        for (int i = 1; i <= n; i++) 
        {
            if (que[b[i]].empty()) goto away;
            a[que[b[i]].front()].des = i;
            que[b[i]].pop();
        }
        for (int i = 1; i <= m; i++) 
            sort(a + quest[i].first, a + 1 + quest[i].second, cmp);
        for (int i = 1; i <= n; i++)
        {
            if (a[i].num != b[i]) goto away;
        }
        printf("TAK\n"); continue;
        away: printf("NIE\n");
    }
    return 0;
}