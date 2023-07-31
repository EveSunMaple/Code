#include<iostream>
using namespace std;

int NUM[10001];

int cnt = 1;

int gcd(int a, int b)
{
	return b == 0 ? a : gcd(b, a % b);
} 

int main()
{
	int x = 0, y = 0;
	cin >> x >> y;
	
	int max = x * y;
	
	int ans = 0;
	int cnt = 0;
	
	for(int i = 1; i * i <= max; i++)
	{
		int t = max / i;
		if(!(max % i) && gcd(t, i) == x)
		{
			if(i * i == max)
				ans++;
			else
				ans += 2;
		}
			
	}
	
	cout << ans;
	
	return 0;
}