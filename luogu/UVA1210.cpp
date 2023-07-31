#include<iostream>
#include<cstring>

using namespace std;

bool NUM[10003];
int prime[1003];

int cnt = 1;

int make(int n)
{
	int sum = 0;
	int ans = 0;
	int l = 1, r = 1;
	
	sum = prime[1];
	
	for(; ;)
	{
		if(sum < n) 
		{
			sum += prime[++r];
		}
		if(sum == n) 
		{
			sum += prime[++r]; 
			ans++;
		}
		if(sum > n) 
		{
			sum -= prime[++l];
		}
		
		if(sum <= n && r == cnt + 1)
		{
			return ans;
		}
	}
}

int main()
{
	memset(NUM, 0, sizeof(NUM));
	
	NUM[1] = 1;
	
	for(int i = 2; i * i < 10003; i++)
	{
		for(int j = i * 2; j < 10003; j += i)
		{
			NUM[j] = 1;
		}
	}
	
	for(int i = 1; i < 10003; i++)
	{
		if(!NUM[i])
		{
			prime[++cnt] = i;
		}
	}
	
	for(; ;)
	{
		int n = 0;
		cin >> n;
		
		if(n)
		{
			cout << make(n) << endl;
		}
		else
			return 0;
	}
	
	return 0;
}