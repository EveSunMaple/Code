#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#define fastio                   \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0)

using namespace std;

int main()
{
    fastio;
    freopen("median.in", "r", stdin);
    freopen("median.out", "w", stdout);
    int T, a[200005];
    scanf("%d", &T);
    while (T--)
    {
        int n, k;
        scanf("%d%d", &n, &k);
        for (int i = 1; i <= n; i++) scanf("%d", &a[i]); 
        sort(a + 1, a + 1 + n);
        int temp = 1, crd = (n + 1) >> 1;
        int aim = a[crd];
        while (k >= temp)
        {
            for (int i = crd + 1; i <= n; i++)
            {
                if (a[i] == aim) temp++;
                else break;
                crd++;
            }
            if (k < temp) break;
            k -= temp;
            aim++;
        }
        printf("%d\n", aim);
    }
    return 0;
}