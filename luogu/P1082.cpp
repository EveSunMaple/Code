#include <iostream>
#include <iostream>

using namespace std;

long long x = 0, y = 0;

int gcd(long long a, long long b, long long &x, long long &y)
{
	if(b == 0)
	{
		x = 1, y= 0;
		return a;
	}
	
	long long d = gcd(b, a % b, x, y);
	
	long long z = x;
	x = y;
	y = z - (a / b) * y;
	
	return d;
} 

int main()
{
	long long a = 0, b = 0;
	cin >> a >> b;
	
	int d = gcd(a, -b, x, y);
	
	x = x / d;
	y = b / d;
	
	//cout << x << ' ' << y << endl;
	
	if(x > 0)
	{
		x -= (abs(x) / abs(y)) * abs(y);
	}
	else
	{
		x += (abs(x) / abs(y) + 1) * abs(y);
	}
	
	cout << x;
	
	return 0;
}
