#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>

using namespace std;

int N;
int sum[105];
int num[105];
int max_ans = -1;
int min_ans = 1e9;
int max_sum[205][205][205];
int min_sum[205][205][205];

int main()
{
    memset(min_sum, 0x3f, sizeof(min_sum));

    scanf("%d", &N);

    for(int t = 0; t <= N; t++)
        for(int i = 1; i <= N * 2; i++) 
            min_sum[t][i][i] = 0;
    for(int i = 1; i <= N; i++) 
    {
        scanf("%d", &num[i]);
        sum[i] = sum[i - 1] + num[i];
    }
    for(int i = 1; i <= N; i++) sum[i + N] = sum[i + N - 1] + num[i];
    
    for(int t = 0; t <= N; t++)
    {
        for(int len = 2; len <= N; len++)
        {
            for(int l = t; l <= N - len + 1 + t; l++)
            {
                int r = l + len - 1;
                for(int k = l; k < r; k++)
                {
                    max_sum[t][l][r] = max(max_sum[t][l][r], max_sum[t][l][k] + max_sum[t][k + 1][r]);
                    min_sum[t][l][r] = min(min_sum[t][l][r], min_sum[t][l][k] + min_sum[t][k + 1][r]);
                }
                max_sum[t][l][r] += sum[r] - sum[l - 1];
                min_sum[t][l][r] += sum[r] - sum[l - 1];
                max_ans = max(max_ans, max_sum[t][l][r]);
                //cout << "L  " << l << "  R  " << r << endl;
                //cout << min_sum[t][l][r] << " " << sum[r] << " " << sum[l - 1] << endl;
            }
        }
    }

    for(int t = 0; t <= N; t++)
    {
        for(int i = 0; i <= N; i++)
            if(min_sum[t][i + t][i + N - 1 + t] != 0)
                min_ans = min(min_ans, min_sum[t][i + t][i + N - 1 + t]);
    }

    printf("%d\n%d", min_ans, max_ans);

    return 0;
}