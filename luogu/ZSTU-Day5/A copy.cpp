#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#define N 100005

using namespace std;

int a[N];
struct A
{
    int sum;
    vector<pair<int, int>> has;
};


A dp[256];
bool tag[N][8];

int main()
{
    int n, q;
    scanf("%d%d", &n, &q);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
        // for (int j = 0; j < 8; j++)
        //     tag[i][j] = (a[i] >> j) & 1;
    }
    while (q--)
    {
        int l, r, x, ans = 0;
        scanf("%d%d%d", &l, &r, &x);
        // memset(dp, 0, sizeof(dp));
        // memset(aim, false, sizeof(aim));
        // for (int i = 0; i < 8; i++)
        //     aim[i] = (x >> i) & 1;
        vector<int> fix;
        for (int i = l; i <= r; i++)
        {
            if ((a[i] | x) > x) continue;
            fix.push_back(a[i]);
        }
		printf("Now has:\n");
		for (int t : fix) printf("%d ", t);
		printf("\n");
        for (unsigned int i = 0; i < fix.size() - 1; i++)
        {
            for (unsigned int j = 0; j < i; j++)
            {
                dp[fix[j] | fix[i]].sum++;
                dp[fix[j] | fix[i]].has.push_back({fix[j], fix[i]});
            }
			int j = i + 1;
			printf("Now to Find [%d]\n", fix[j]);
            for (int t = 1; t <= 255; t++)
            {
                if ((t | fix[j]) == x) 
				{
					if (dp[t].sum) printf("%d | %d -> <%d>\n", t, fix[j], dp[t].sum);
                    for (pair<int, int> tmp : dp[t].has)
                    {
                        printf("(%d, %d, %d) = %d\n", tmp.first, tmp.second, fix[j], x);
                    }
					printf("\n");
					ans += dp[t].sum;
				}
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
