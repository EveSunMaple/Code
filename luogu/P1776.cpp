#include <iostream>
#include <cstdio>
#include <cmath>
#define MAX 100005

using namespace std;

int N, V;
int W[MAX]; // 记录价值
int M[MAX]; // 记录重量
int DP[MAX]; // 状态转移数组
int tot; // 记录物品个数

int main()
{
    scanf("%d%d", &N, &V);
    for(int i = 1; i <= N; i++)
    {
        int w, m, s;
        scanf("%d%d%d", &w, &m ,&s);
        for(int j = 1; s - j >= 0; j <<= 1 )  // 二进制拆分优化
	  	{
	  	  	tot++;
	  	  	W[tot] = w * j;
	  	  	M[tot] = m * j;
	  	  	s -= j;
	  	}
	  	if(s) // 如果还有剩下的
	  	{
	  	  	tot++;
	  	  	W[tot] = w * s;
	  	  	M[tot] = m * s;
	  	}
    }
    //0-1背包
    for(int i = 1;i <= tot; i++)
	{
	  	for(int j = V; j >= M[i]; j--)
	  	{
	  	  	DP[j] = max(DP[j], DP[j - M[i]] + W[i]);
	  	}
	}
	printf("%d", DP[V]);
    return 0;
}