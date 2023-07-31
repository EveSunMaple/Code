#include<iostream>
#include<queue>

using namespace std;

deque <int> MIN; 
deque <int> MAX; 

int a[100003];

int main()
{
	int num_max[100003]; 
	
	int n = 0, k = 0;
	cin >> n >> k;
	
	for(int i = 1; i <= n; i++)
		cin >> a[i];
		
	int cnt = 1;
	
	for(int i = 1; i <= n; i++)
	{
		for(;!MIN.empty() && a[i] <= a[MIN.back()];)
		{
			MIN.pop_back();
		}
		MIN.push_back(i);
		for(;!MIN.empty() && i - k >= MIN.front();)
		{
			MIN.pop_front();
		}
		
		for(;!MAX.empty() && a[i] >= a[MAX.back()];)
		{
			MAX.pop_back();
		}
		MAX.push_back(i);
		for(;!MAX.empty() && i - k >= MAX.front();)
		{
			MAX.pop_front();
		}
		
		if(i >= k)
		{
			cout<< a[MIN.front()] << ' ';
			num_max[cnt++] = a[MAX.front()];
		}
	}
	
	cout << endl;
	
	for(int i = 1; i < cnt; i++)
	{
		cout << num_max[i] << ' ';
	}
	
	return 0;
} 
