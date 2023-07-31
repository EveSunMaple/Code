#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
	int n, l;
	int p = 0;
	int a_min = 0, a_max = 0;
	
	cin>> l >> n;
	
	for(int i = 1; i <= n; i++)
	{
		cin>> p;
		a_min=max(a_min, min(l - p + 1, p));
		a_max=max(a_max, max(l - p + 1, p));
	}
	
	cout<< a_min << " " << a_max;
	
	return 0;
}
