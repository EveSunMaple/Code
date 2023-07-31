#include<iostream>
#include<algorithm>

using namespace std;

int N[100003];
int n = 0, c = 0;

bool check(int range)
{
	int start = N[1];
	int sum = 1;
	for(int i = 1; i <= n; i++)
	{
		if(N[i] - start >= range)
		{
			start = N[i];
			sum++;
			if(sum >= c)
				return true;
		}
	}
	
	return false;
}

int main()
{
	cin>> n >> c;
	for(int i = 1; i <= n; i++)
		cin>> N[i];
	
	sort(N + 1, N + 1 + n);
	
	int l = 1, r = N[n];
	int mid = (l + r) / 2;
	
	for(; ;)
	{
		/*
		for(int i = 1; i <= N[n]; i++)
		{
			cout<< i;
		}
		cout<< endl;
		for(int i = 1; i <= N[n]; i++)
		{
			if(r == i)
				cout<< 'r';
			else if(l == i)
				cout<< 'l';
			else
				cout<<' ';
		}
		cout<< endl;
		*/
		
		if(check(mid))
		{
			l = mid;
		}
		else
		{
			r = mid;
		}
		mid = (l + r) / 2;
		
		if(r <= l + 1)
		{
			cout<< l;
			return 0;
		}
	}
}