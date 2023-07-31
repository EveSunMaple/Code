#include<iostream>
#include<cstring>
 
using namespace std;

char s[103][103];
int x = 0, y = 0;
int M = 0, N = 0;

bool find()
{
	for(int i = 1; i <= N; i++)
	{
		for(int j = 1; j <= M; j++)
		{
			if(s[i][j] == 'W')
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
    s[x][y] = '.';
    for(int i = -1; i <= 1; i++)
	{
        for(int j = -1; j <= 1; j++)
        {
            if(s[x + i][y + j] == 'W')
            {
                dfs(x + i, y + j);
            }
        }
	}
	
	return;
}

int main()
{
    memset(s, 0, sizeof(s));
	
    cin>> N >> M;
	
    for(int i = 1; i <= N; i++)
    {
        for(int j = 1; j <= M; j++)
        {
            cin>> s[i][j];
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
