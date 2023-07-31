#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

long long cnt[31][31];
int n = 0, m = 0;

int main()
{
	int x = 0, y = 0;
	scanf("%d %d", &x, &y);
	scanf("%d %d", &n, &m);
	
	cnt[0][0] = 1;
	cnt[n][m] = -1;
	
	//init
	for(int i = n - 2; i <= n + 2; i++)
	{
		for(int j = m - 2; j <= m + 2; j++)
		{
			if(i != n && j != m && abs(n - i) != abs(m - j) && i >= 0 && j >= 0 && i <= x && j <= y)
			{
				cnt[i][j] = -1;
			}
		}
	}
	
	for(int i = 0; i <= x; i++)
	{
		for(int j = 0; j <= y; j++)
		{
			if(cnt[i][j] >= 0 && cnt[i + 1][j] >= 0)
			{
				cnt[i + 1][j] += cnt[i][j];
			}
			if(cnt[i][j] >= 0 && cnt[i][j + 1] >= 0)
			{
				cnt[i][j + 1] += cnt[i][j];
			}
		}
	}
	cout << cnt[x][y];
	
	return 0;
}
