#include <iostream>

using namespace std;

int MAP[33][33];
int n = 0; 

int x = 0, y = 0;

void dfs(int x, int y)
{
	MAP[x][y] = 2;
	if(MAP[x + 1][y] == 0 && x + 1 <= n) {dfs(x + 1, y);}
	if(MAP[x - 1][y] == 0 && x - 1 >= 1) {dfs(x - 1, y);}
	if(MAP[x][y + 1] == 0 && y + 1 <= n) {dfs(x, y + 1);}
	if(MAP[x][y - 1] == 0 && y - 1 >= 1) {dfs(x, y - 1);}
	return;
}

int main()
{
	cin >> n;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
		{
			cin >> MAP[i][j];
			if(MAP[i][j] == 1 && x == 0 && y == 0)
			{
				x = i + 1;
				y = j + 1;
			}
		}
	
	dfs(x, y);
		
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= n; j++)
		{
			cout << MAP[i][j] << ' ';
		}
		cout << endl;
	}	
	return 0;
}
