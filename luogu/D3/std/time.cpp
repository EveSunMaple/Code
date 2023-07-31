#include <bits/stdc++.h>
using namespace std;

const int N = 100000;

int n;
int c[N + 5];
deque<int> q[N + 5];

void add(int x, int y)
{
    for (int i = x; i <= n; i += i & (-i))
    {
        c[i] += y;
    }
}

int query(int x)
{
    int ans = 0;
    for (int i = x; i > 0; i -= i & (-i))
    {
        ans += c[i];
    }
    return ans;
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
    {
        int x;
        scanf("%d", &x);
        q[x].push_back(i);
        add(i, 1);
    }

    long long ans = 0;
    for (int i = 1; i <= N; ++i)
    {
        while (q[i].size())
        {
            int x = q[i].front(), a = query(x - 1);
            int y = q[i].back(), b = query(n) - query(y);

            if (a < b)
            {
                ans += a;
                add(x, -1);
                q[i].pop_front();
            }
            else
            {
                ans += b;
                add(y, -1);
                q[i].pop_back();
            }
        }
    }
    printf("%lld\n", ans);

    return 0;
}
