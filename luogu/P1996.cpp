#include<iostream>
#include<cstring>

using namespace std;

int queue[203];

int main()
{
	memset(queue, -1, sizeof(queue));
	
	int n = 0, m = 0;
	cin >> n >> m;
	
	for(int i = 1; i <= n; i++)
	{
		queue[i] = i;
	}
	
	for(int i = 1, num = 0, j = 1; num < n;)
	{
		//cout << queue[i] << ' ';
		if(queue[i] > 0)
		{
			if(j == m)
			{
				cout << queue[i] << ' ';
				queue[i] = 0;
				j = 0;
				num++;
			}
			j++;
		}
		if(queue[i] == -1)
		{
			i = 0;
			//cout << endl; 
		} 
		i++;
	}
}
