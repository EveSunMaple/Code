#include <iostream>

using namespace std;

int sum[1002][102];

int main()
{
	int T, M;
	scanf("%d %d", &T, &M);
	
	int ans = 0;
	
	for(int i = 1; i <= M; i++)
	{
		int t, s;
		scanf("%d %d", &t, &s);
		for(int j = T; j >= 0; j--)
		{
			sum[i][j] = sum[i - 1][j];
			if(t <= j)
			{
			//cout << s + sum[i - 1][j - t] << '-' << sum[i][j] << '|';
				sum[i][j] = max(sum[i][j], s + sum[i - 1][j - t]);
			}
			//cout << sum[i][j] << ' ';
			if(ans < sum[i][j])
			{
				ans = sum[i][j];
			}
		}
		//cout << endl;
	}
	
	printf("%d", sum[M][T]);
	
	return 0;
}
