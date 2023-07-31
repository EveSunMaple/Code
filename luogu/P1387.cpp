#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

int map[102][102];
int cnt[102][102];

int main()
{
	int n = 0, m = 0;
    scanf("%d %d", &n, &m);

    int ans = 0;

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            scanf("%d", &map[i][j]);
            if(map[i][j])
            {
                cnt[i][j] = min(min(cnt[i][j - 1], cnt[i - 1][j]), cnt[i - 1][j - 1]) + 1;
            }
            ans = max(ans, cnt[i][j]);
        }
    }

    printf("%d", ans);
    
	return 0;
}
