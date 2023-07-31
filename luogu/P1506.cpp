#include<iostream>
#include<cstring>

using namespace std;

char M[503][503];
int x = 0, y = 0;
int n = 0, m = 0;
bool f = 0;
	
int ans = 0;

bool find()
{
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= m; j++)
		{
			if(M[i][j] == '0')
			{
				x = i;
				y = j;
				
				return 1;
			}
		}
	}
	
	return 0;
}

void dfs(int x, int y, bool f)
{
	M[x][y] = '*';
    if(f)
        ans++;
	if(M[x + 1][y] == '0')
		dfs(x + 1, y, f);
	if(M[x - 1][y] == '0')
		dfs(x - 1, y, f);
	if(M[x][y + 1] == '0')
		dfs(x, y + 1, f);
	if(M[x][y - 1] == '0')
		dfs(x, y - 1, f); 
	
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
	
	for(; ;)
	{
		if(find())
		{
            if(!((x == 1 || x == n) || (y == 1 || y == m)))
			    f = 1;
			else
			    f = 0;
			dfs(x, y, f);
		}
		else
		{
			break;
		}
	}
	
	cout<< ans;
    
	return 0;
} 