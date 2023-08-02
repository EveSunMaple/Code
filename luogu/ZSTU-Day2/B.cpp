#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#define N 2000050
#define pal pair<int, int>

using namespace std;

vector<int> num;
int d[N], tot;
int have[N / 10];
bool tag[N];
bool cut[N];
pal edge[N];

int dfs(int u, bool way)
{
    have[num[u]]--;
    if (!have[num[u]]) tag[tot + u] = true;
    int sum = 0;
    if (edge[tot + u].first >= 0 && !tag[tot + edge[tot + u].first])
    {
        // printf("%d[%d] goto %d[%d]\n", u, num[u], edge[tot + u].first, num[edge[tot + u].first]);
        sum += dfs(edge[tot + u].first, !way);
        if (way) 
        {
            sum++;
            cut[tot + u] = true;
            cut[tot + edge[tot + u].first] = true;
            if (edge[tot + u].first != u) sum++;
        }
    }
    if (edge[tot + u].second >= 0 && !tag[tot + edge[tot + u].second])
    {
        // printf("%d[%d] goto %d[%d]\n", u, num[u], edge[tot + u].second, num[edge[tot + u].second]);
        sum += dfs(edge[tot + u].second, !way);
        if (way) 
        {
            sum++;
            cut[tot + u] = true;
            cut[tot + edge[tot + u].second] = true;
            if (edge[tot + u].second != u) sum++;
        }
    }
    return sum;
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n, a, b;
        num.clear();
        memset(have, 0, sizeof(have));
        scanf("%d%d%d", &n, &a, &b);
        for (int i = 1; i <= n; i++)
        {
            int temp;
            scanf("%d", &temp);
            num.push_back(temp);
            have[temp]++;
        }
        sort(num.begin(), num.end());
        for (int i = 0; i < num.size(); i++)
        {
            edge[tot + i].first = -1;
            edge[tot + i].second = -1;
            int temp = num[i];
            int a_num = a - temp;
            int b_num = b - temp;
            if (binary_search(num.begin(), num.end(), a_num))
                { edge[tot + i].first = lower_bound(num.begin(), num.end(), a_num) - num.begin(); d[tot + i]++; }
            if (binary_search(num.begin(), num.end(), b_num))
                {edge[tot + i].second = lower_bound(num.begin(), num.end(), b_num) - num.begin(); d[tot + i]++; }
            // printf("%d: \n l: %d r: %d\n", i, edge[tot + i].first, edge[tot + i].second);
        }
        int temp = n;
        for (int i = 0; i < temp; i++)
        {
            // printf("%d: \n tag: %d d: %d\n", i, tag[tot + i], d[tot + i]);
            if (!tag[tot + i] && d[tot + i] == 1)
            {
                n -= dfs(i, 1);
            }
        }
        for (int i = 0; i < temp; i++)
        {
            if (!cut[tot + i])
            {
                if (edge[tot + i].first == i || edge[tot + i].second == i)
                {
                    cut[tot + i] = true;
                    n--;
                }
            }
        }
        tot += temp;
        // printf("%d\n", n);
        if (n) printf("NO\n");
        else printf("YES\n");
    }
    return 0;
}