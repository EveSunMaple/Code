#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <cmath>

using namespace std;

vector<int> w[1500];
vector<int> d[1500];
int f[1500];

int main()
{
    int N, M, K;
    scanf("%d %d", &M, &N);

    for(int i = 1; i <= N; i++)
    {
        int W, D, k;
        scanf("%d %d %d", &W, &D, &k);
        w[k].push_back(W);
        d[k].push_back(D);
        K = max(K, k);
    }

    for(int k = 0; k <= K; k++)
    {
        for(int j = M; j >= 0; j--)
        {
            for(int i = 0; i < w[k].size(); i++)
            {
                if(j >= w[k][i])
                    f[j] = max(f[j], f[j - w[k][i]] + d[k][i]);
            }
        }
    }

    cout << f[M];

    return 0;
}