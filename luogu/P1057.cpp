#include <iostream>
#include <cstdio>

using namespace std;

long long cnt[31][31];
int n = 0, m = 0;

int main()
{
	scanf("%d %d", &n, &m);
	
	cnt[0][1] = 1;
	
	for(int i = 0; i < m; i++)
	{
		for(int j = 1; j <= n; j++)
		{
			if(cnt[i][j] >= 1)
			{
				int r = (j + 1) % n;
				int l = (n + j - 1) % n;
				if(r == 0) r = n;
				if(l == 0) l = n;
				cnt[i + 1][r] += cnt[i][j];
				cnt[i + 1][l] += cnt[i][j];
			}
		}
	}
	
	cout << cnt[m][1];
	
	return 0;
}
