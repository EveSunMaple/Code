#include<iostream>
#include<cstring>
#include<queue>

using namespace std;

//deque <int> ans;

int ans[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
bool N[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

void dfs(int n, int node, int step)
{
	for(int i = 1; i <= n; i++)
	{
		if(!N[i])
		{
			ans[step] = i;
			N[i] = 1;
			dfs(n, i, step + 1);
		}
		else
			continue;
	}
	
	if(step == n)
	{
		for(int i = 1; i <= n; i++)
		{
			cout<< "    " << ans[i];
		}
		cout<<endl;
	}
	
	N[node] = 0;
	//ans[step] = 0;
	
	return;
}

int main()
{
	int n = 0;
	cin>> n;
	
	dfs(n, 0, 1);
	return 0;
}