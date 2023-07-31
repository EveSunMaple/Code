#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

long long cnt[1005][1005];
int n = 0, m = 0;

int main()
{
	int N = 0, M = 0;
	scanf("%d %d", &N, &M);
	
	cnt[1][1] = 1;
	
	//init
	for(int i = 1; i <= M; i++)
	{
		int x, y;
		scanf("%d %d", &x, &y);
		cnt[x][y] = -1;
	}
	
	for(int i = 1; i <= N; i++)
	{
		for(int j = 1; j <= N; j++)
		{
			if(cnt[i][j] >= 0 && cnt[i + 1][j] >= 0)
			{
				cnt[i + 1][j] += cnt[i][j] % 100003;
			}
			if(cnt[i][j] >= 0 && cnt[i][j + 1] >= 0)
			{
				cnt[i][j + 1] += cnt[i][j] % 100003;
			}
			cnt[i][j] %= 100003;
			//printf("%d \n", cnt[i][j]);
		}
	}
	cout << cnt[N][N];
	
	return 0;
}
