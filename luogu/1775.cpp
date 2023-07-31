#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>

using namespace std;

int N;
int sum[305];
int num[305];
int max_ans = -1;
int min_ans = 1e9;
int max_sum[305][205];
int min_sum[305][305];

int main()
{
    memset(min_sum, 0x3f, sizeof(min_sum));
    scanf("%d", &N);
    for(int i = 1; i <= N; i++) 
    {
        scanf("%d", &num[i]);
        sum[i] = sum[i - 1] + num[i];
    }

    for(int i = 0; i <= N; i++) 
        min_sum[i][i] = 0;
    for(int len = 2; len <= N; len++)
    {
        for(int l = 0; l <= N - len + 1; l++)
        {
            int r = l + len - 1;
            for(int k = l; k < r; k++)
            {
                min_sum[l][r] = min(min_sum[l][r], min_sum[l][k] + min_sum[k + 1][r]);
            }
            min_sum[l][r] += sum[r] - sum[l - 1];
        }
    }

    printf("%d\n", min_sum[1][N]);

    return 0;
}