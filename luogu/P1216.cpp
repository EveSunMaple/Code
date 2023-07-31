#include <iostream>
#include <cstdio>

using namespace std;

int map[10002][10002];
int SUM[10002][10002];
int n = 0;

int main()
{
	scanf("%d", &n);//∂¡»°n
	
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= i; j++)
		{
			scanf("%d", &map[i][j]);
			SUM[i][j] = map[i][j]; 
		}
	}
	
	int ans = 0;
	
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= i; j++)
		{
			if(map[i + 1][j] + SUM[i][j] > SUM[i + 1][j])
			{
				SUM[i + 1][j] = map[i + 1][j] + SUM[i][j];
			}
			if(map[i + 1][j + 1] + SUM[i][j] > SUM[i + 1][j + 1])
			{
				SUM[i + 1][j + 1] = map[i + 1][j + 1] + SUM[i][j];
			}
			if(SUM[i][j] > ans)
				ans = SUM[i][j];
		}
	}
	
	printf("%d", ans);
	
	return 0;
} 
