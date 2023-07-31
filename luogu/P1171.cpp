#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>

using namespace std;

//DP[i][j]表示从起点到第j号点 且到达时状态恰好为i的最短路
int DP[1 << 20][20]; // 1 << 20代表村庄数为20时的所有情况
int map[20][20]; //下标从0开始 代表从a -> b的路程

int main()
{
    int n = 0;
    scanf("%d", &n);
    memset(DP, 0x3f, sizeof(DP));
    DP[1][0] = 0; //加入起点，代表只从商店出发时路程为0
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            scanf("%d", &map[i][j]);
    
    for(int t = 1; t <= (1 << n); t += 2) //枚举村庄树为n时的经过情况，用t存储，此时不要求经过所有村庄
    {
        for(int i = 0; i < n; i++) //当前t情况下走到的村庄i
        {
            if(!(t >> i & 1)) continue; //如果当前t情况下并没有经过村庄i，跳过
            for(int j = 0; j < n; j++) //枚举从村庄j -> i的情况
            {
                if(j == i) continue; //不能从自己走到自己
				if(!(t >> j & 1)) continue; //如果当前t情况下并没有经过村庄j，跳过
                /*
                更新当前t情况的值
                t ^ (1 << i)代表把t状态中的i村庄拿走时的状态值
                DP[t ^ (1 << i)][j] + map[j][i]则是此时有可能更优的值
                */
                DP[t][i] = min(DP[t][i], DP[t ^ (1 << i)][j] + map[j][i]);
            }
        }
    }

    int ans = 0x7fffffff;
    /*
    枚举所有情况，DP状态最后一个村庄为i
    状态值是(1 << n) - 1
    同时加上最后回到村庄的路程
    */
	for(int i = 1; i <= n - 1; i++)
	{
		ans = min(ans, DP[(1 << n) - 1][i] + map[i][0]);
	}

    printf("%d", ans);

    return 0;
}