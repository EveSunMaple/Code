#include<iostream>
#include<cstring>

using namespace std;

char M[100001][101];
int x = 0, y = 0;
int n = 0, m = 0;

bool find()
{
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= m; j++)
		{
			if(M[i][j] > '0')
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
	M[x][y] = '0';
	if(M[x + 1][y] > '0')
		dfs(x + 1, y);
	if(M[x - 1][y] > '0')
		dfs(x - 1, y);
	if(M[x][y + 1] > '0')
		dfs(x, y + 1);
	if(M[x][y - 1] > '0')
		dfs(x, y - 1); 
	
	return;
}

int main()
{
	memset(M, '0', sizeof(M));
	
	cin>> n >> m;
	
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= m; j++)
		{
			char a;
			cin>> a;
			M[i][j] = a;
		}
	}
	
	int ans = 0;
	
	for(; ;)
	{
		if(find())
		{
			ans++;
			dfs(x, y);
		}
		else
		{
			break;
		}
	}
	
	cout<< ans;
    
	return 0;
} 
