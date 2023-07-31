#include <iostream>
#include <cstdio>

using namespace std;

int SUM[30003][30];
int n = 0, m = 0;

int main()
{
	scanf("%d %d", &n ,&m);//读取n m 
	
	int ans = 0;
	
	for(int i = 1; i <= m; i++)
	{
		int v = 0, w = 0; //v:价钱 w:等级 
		scanf("%d %d", &v ,&w);//读取v w 
		for(int j = n; j >= 0; j--)
		{
			SUM[j][i] = SUM[j][i - 1]; 
			if(j >= v)
			{
				SUM[j][i] = max(SUM[j][i - 1], SUM[j - v][i - 1] + w * v);
			}
			if(SUM[j][i] > ans)
				ans = SUM[j][i];
		}
	}
	
	printf("%d", ans);
	
	return 0;
} 
