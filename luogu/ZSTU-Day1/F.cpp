#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <queue>
#define N 1000005
#define pal pair<long long, long long>

using namespace std;

bool cmp(pal a, pal b)
{
    if (a.first > b.first) return true;
    if (a.first < b.first) return false;
    return a.second > b.second;
}

pal num[N];

int main()
{
    // priority_queue<pair<long long, long long>> q;
    long long n, max_x = 0, max_y = 0;
    scanf("%lld", &n);
    for (int i = 1; i <= n; i++)
    {
        long long x, y;
        scanf("%lld%lld", &x, &y);
        x /= 2; y /= 2;
        max_x = max(max_x, x);
        max_y = max(max_y, y);
        num[i] = {x, y};
        // q.push({x, y});
    }
    sort(num + 1, num + 1 + n, cmp);
    long long ans = max_x * max_y;
    long long now_y = num[1].second;
    // long long now_y = q.top().second;
    // q.pop();
    for (int i = 2; i <= n; i++)
    {
        // pair<long long, long long> temp = q.top();
        // q.pop();
        pal temp = num[i];
        if (temp.second <= now_y) continue;
        ans -= (temp.second - now_y) * (max_x - temp.first);
        now_y = temp.second;
    }
    printf("%lld", ans * 4);
    return 0;
}