#include<iostream>
#include<cstring>
#include<queue>

using namespace std;

deque<int>M;
int a[1000001];

int main()
{
	int n, m;
	cin>> n >> m;
	for(int i = 1; i <= n; i++)
		cin>>a[i];
	for(int i = 1; i <= n; i++)
	{
		for(;!M.empty() && a[i] <= a[M.back()];)
		{
			M.pop_back();
		}
		M.push_back(i);
		for(;!M.empty() && i - m >= M.front();)
		{
			M.pop_front();
		}
		if(i >= m)
			cout<< a[M.front()] <<endl;
	}
	return 0;
}