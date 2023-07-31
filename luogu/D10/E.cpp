#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#define N 200005

using namespace std;

int sum[N];
int MAX[N];
int MIN[N];
int tot = 1;

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n;
        scanf("%d", &n);
        memset(MAX, 0, sizeof(MAX));
        memset(MIN, 0, sizeof(MIN));
        sum[1] = 1;
        MAX[1] = 1;
        MIN[1] = 0;
        for (int i = 1; i <= n; i++)
        {
            char op;
            cin >> op;
            if (op == '+')
            {
                int u, w;
                scanf("%d%d", &u, &w);
                sum[++tot] = sum[u] + w;
                MAX[tot] = max(max(w, MAX[u] + w), max(sum[tot], MAX[u]));
                MIN[tot] = min(min(w, MIN[u] + w), min(sum[tot], MIN[u]));
            }
            else if (op == '?')
            {
                int u, v, k;
                scanf("%d%d%d", &u, &v, &k);
                if ((k >= MIN[v] && k <= MAX[v]) || k == 0) printf("YES\n");
                else printf("NO\n");
            }
        }
    }
    return 0;
}