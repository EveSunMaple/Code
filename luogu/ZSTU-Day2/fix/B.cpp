#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#define N 1000005
#define pal pair<int, int>

using namespace std;

vector<int> num;
int d[N], tot;
bool tag[N];
bool cut[N];
pal edge[N];

int dfs(int u, bool way)
{
    tag[u] = true;
    int sum = 0;
    if (edge[u].first >= 0 && !tag[edge[u].first])
    {
        sum += dfs(edge[u].first, !way);
        if (way) 
        {
            sum++;
            cut[u] = true;
            cut[edge[u].first] = true;
            if (edge[u].first != u) sum++;
        }
    }
    if (edge[u].second >= 0 && !tag[edge[u].second])
    {
        sum += dfs(edge[u].second, !way);
        if (way) 
        {
            sum++;
            cut[u] = true;
            cut[edge[u].second] = true;
            if (edge[u].second != u) sum++;
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
        memset(edge, 0, sizeof(edge));
        memset(tag, 0, sizeof(tag));
        memset(cut, 0, sizeof(cut));
        memset(d, 0, sizeof(d));
        scanf("%d%d%d", &n, &a, &b);
        for (int i = 1; i <= n; i++)
        {
            int temp;
            scanf("%d", &temp);
            num.push_back(temp);
        }
        sort(num.begin(), num.end());
        for (int i = 0; i < num.size(); i++)
        {
            edge[i].first = -1;
            edge[i].second = -1;
            int temp = num[i];
            int a_num = a - temp;
            int b_num = b - temp;
            if (binary_search(num.begin(), num.end(), a_num))
                { edge[i].first = lower_bound(num.begin(), num.end(), a_num) - num.begin(); d[i]++; }
            if (binary_search(num.begin(), num.end(), b_num))
                {edge[i].second = lower_bound(num.begin(), num.end(), b_num) - num.begin(); d[i]++; }
        }
        int temp = n;
        for (int i = 0; i < temp; i++)
        {
            if (!tag[i] && d[i] == 1) n -= dfs(i, 1);
        }
        for (int i = 0; i < temp; i++)
        {
            if (!cut[i] && (edge[i].first == i || edge[i].second == i)) n--;
        }
        if (n) printf("NO\n");
        else printf("YES\n");
    }
    return 0;
}