#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>

using namespace std;

int N, M;
int A[505], B[505];
int dp[2][505]; // 使用滚动数组优化空间复杂度
int path[505][505];
int p[505];
int tot = 0;

int main()
{
    memset(path, -1, sizeof(path));
    memset(dp, -1, sizeof(dp));
    scanf("%d", &N);
    for(int i = 1; i <= N; i++) scanf("%d", &A[i]);
    scanf("%d", &M);
    for(int i = 1; i <= M; i++) scanf("%d", &B[i]);
    int ans = 0;
    for(int i = 1; i <= N; i++)
    {
        int S = 0;
        int k = 0;
        for(int j = 1; j <= M; j++)
        {
            dp[i % 2][j] = dp[(i - 1) % 2][j];
            if(A[i] == B[j] && dp[i % 2][j] < S + 1) 
            {
                dp[i % 2][j] = S + 1;
                path[i][j] = k; // k 是使得 dp[(i - 1) % 2][k] 最大的下标
            }
            if(A[i] > B[j] && S < dp[(i - 1) % 2][j]) 
            {
                S = dp[(i - 1) % 2][j];
                k = j;
            }
        }
    }

    int max_j = 1; // max_j 是使得 dp[N % 2][j] 最大的下标

    for(int j = 1; j <= M; j++)
    {
        ans = max(ans, dp[N % 2][j]);
        if(dp[N % 2][j] > dp[N % 2][max_j])
        {
            max_j = j;
        }
    }

    printf("%d\n", ans);

    for(int i = N, j = max_j; i > 0 && j > 0; i--)
    {
        if(path[i][j] != -1)
        {
            p[++tot] = B[j];
            j = path[i][j];
        }
    }

    for(int i = tot; i >= 1; i--) printf("%d ", p[i]);

    return 0;
}