#include <iostream>
#include <vector>
#include <cstdio>
#include <cmath>
#include <algorithm>
#define MAX 2005
#define p 1000000007

using namespace std;

int N, K;
int line[MAX][MAX];
vector<int> need[MAX];

int main()
{
    scanf("%d %d", &N, &K);
    for(int i = 1; i <= N; i++) line[1][i] = 1;

    for(int i = 2; i <= K; i++)
    {
        for(int j = 1; j <= N; j++)
        {
            for(int t = 1; t * j <= N; t++)
            {
                line[i][j] = (line[i][j] + line[i - 1][j * t]) % p;
            }
        }
    }

    int ans = 0;
    for(int i = 1; i <= N; i++) ans = (ans + line[K][i]) % p;
    printf("%d", ans);

    return 0;
}