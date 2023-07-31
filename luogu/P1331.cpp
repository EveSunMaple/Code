#include<iostream>
#include<cstring>

using namespace std;

char M[1001][1001];
int sum[1001][1001];
int x = 0, y = 0;
int a = 1000, b = 1000;
int l = 0, h = 0;
int R, C;

bool find()
{
	for(int i = 1; i <= R; i++)
	{
		for(int j = 1; j <= C; j++)
		{
			if(M[i][j] == '#')
			{
				x = i;
				y = j;
				return 1;
			}
		}
	}
	return 0;
}

void dfs(int x, int y)
{
	M[x][y] = '.';
	if(M[x + 1][y] == '#')
		dfs(x + 1, y);
	if(M[x][y + 1] == '#')
		dfs(x, y + 1);
	if(M[x - 1][y] == '#')
		dfs(x - 1, y);
	if(M[x][y - 1] == '#')
		dfs(x, y - 1);
	
	if(x < a)
		a = x;
	if(y < b)
		b = y;
	if(x > l)
		l = x;
	if(y > h)
		h = y;
	
	return;
}

int main()
{
	memset(sum, 0, sizeof(sum));
	cin>> R >> C;
	
	for(int i = 1; i <= R; i++)
	{
		for(int j = 1; j <= C; j++)
		{
			cin>> M[i][j];
			sum[i][j] += sum[i][j - 1] + sum[i - 1][j] - sum[i - 1][j - 1];
			if(M[i][j] == '#')
			{
				sum[i][j]++;
			}
		}
	}
	
	int ans = 0;
	
	for(; ;)
	{
		if(find())
		{
			dfs(x, y);
			
			if((l - a + 1) * (h - b + 1) == sum[l][h] - sum[l][b - 1] - sum[a - 1][h] + sum[a - 1][b - 1])
			{
				ans++;
			}
			else
			{
				cout<<"Bad placement.";
				return 0;
			}
			l = 0;
			h = 0;
			a = 10000;
			b = 10000;
		}
		else
		{
			break;
		}
	}
	
	cout<< "There are " << ans << " ships.";
	
	return 0;
} 
