#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
#define N 100005
#define par pair<int, int>

using namespace std;

pair<int, int> a[N];
pair<int, int> b[N];
int s_a[N], s_b[N];
int n, la, lb;

void init(par p[], int m, int res[])
{
    priority_queue<par, vector<par>, greater<par>> wait;
    priority_queue<int, vector<int>, greater<int>> free;

    for (int i = 1; i <= n; i++) free.push(i);
    for (int i = 1; i <= m; i++) 
    {
        while (!wait.empty() && p[i].first >= wait.top().first) 
        {
            free.push(wait.top().second);
            wait.pop();
        }
        if (free.empty()) continue;
        int temp = free.top();
        free.pop();
        res[temp]++;
        wait.push(make_pair(p[i].second, temp));
    }

    for (int i = 1; i <= n; i++) res[i] += res[i - 1];
}
int main() 
{
    scanf("%d%d%d", &n, &la, &lb);
	for(int i = 1; i <= la; i++) scanf("%d%d", &a[i].first, &a[i].second);
	for(int i = 1; i <= lb; i++) scanf("%d%d", &b[i].first, &b[i].second);
    sort(a + 1, a + la + 1);
    sort(b + 1, b + lb + 1);
    init(a, la, s_a);
    init(b, lb, s_b);
    int ans = 0;
    for (int i = 0; i <= n; i++)
        ans = max(ans, s_a[i] + s_b[n - i]);
    printf("%d", ans);
    return 0;
}