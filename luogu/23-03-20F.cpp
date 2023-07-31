#include<iostream>
#include<cmath>
#include<cstdio>

using namespace std;

int d = 0; //gcd(L, (m - n))

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

bool check(int a, int b)
{
	if(b)
		return 1;
	return 0;
}

int main()
{
	long long x = 1, y = 0;
	long long a = 0, b = 0;
	long long c = 0;
	
	int n = 0;
	scanf("%d", &n); 
	
	//cin >> a >> b >> c;
	
	for(int t = 1; t <= n; t++)
	{ 
		scanf("%lld %lld %lld", &a, &b, &c); 
	
		d = gcd(a, b, x, y);
		
		if(c % d)	//SP
		{
			printf("%d \n", -1);
		}
		
		//cout << "方程1: " << x << 'a' << '+' << (b / d) << 'k' << " + " << y << 'b' << '-' << (a / d) << 'k' << '=' << d << endl;
		
		x *= c / d;
		y *= c / d;
	
		//int t1 = (b / d) / (b / d);
		//int t2 = (a / d) / (a / d);
		//int n1 = x / x; int n2 = y / y;
		
		int i = -x / (b / d);
		int j = -y / (a / d);
		
		//cout << "方程2: " << x << 'a' << '+' << (b / d) << 'k' << " + " << y << 'b' << '-' << (a / d) << 'k' << '=' << c << endl;
		
		//cout << x << ' ' << y << endl;
		//cout << (b / d) << ' ' << -(a / d) << endl;
		//cout << i << ' ' << j << endl;
		
		int ansx_min = x + ((b / d) * i);
		int ansy_max = y + (-(a / d) * i);
		if(ansx_min <= 0)
		{
			ansx_min += (b / d);
			ansy_max += -(a / d);
		}
		
		int ansx_max = x - ((b / d) * j);
		int ansy_min = y - (-(a / d) * j);
		if(ansy_min <= 0)
		{
			ansx_max -= (b / d);
			ansy_min -= -(a / d);
	 	}
	 	
		//=====================================
		if(ansy_max > 0 || ansx_max > 0)
		{
			/*i = abs(x / (b / d));
			j = abs(y / (a / d));
		
			int ansx_min_up = x + abs((b / d) * j);
			int ansy_minx_up = y - abs((a / d) * j);
			if(ansx_min_up == 0)
			{
				ansx_min_up += abs(b / d);
				ansy_minx_up -= abs(a / d);
			}
		
				int ansx_miny_up = x - abs((b / d) * i);
			int ansy_min_up = y + abs((a / d) * i);
				if(ansy_min_up == 0)
			{
				ansx_miny_up -= abs(b / d);
				ansy_min_up += abs(a / d);
			}*/
			
			int num = abs(ansx_max - ansx_min) / abs(b / d) + 1;
			//cout << "正整数解个数：" << num << endl;
				
			//cout << ansx_min << "|" << ansy_max << endl;
			//cout << ansx_max << "|" << ansy_min << endl;
		
			//cout << "最小整数X" << ansx_min << endl;
			//cout << "最小整数Y" << ansy_min << endl;
	
			//cout << "最大整数X" << ansx_max << endl;
			//cout << "最大整数Y" << ansy_max << endl;
			
			printf("%d %d %d %d %d \n", num, ansx_min, ansy_min, ansx_max, ansy_max);
			
			//cout << num << ' ' << ansx_min << ' ' << ansy_min << ' '  << ansx_max << ' '  << ansy_max;
		}
		else
		{
			//cout << "无正整数解" << endl;
				
			//cout << ansx_min << "|" << ansy_max << endl;
			//cout << ansx_max << "|" << ansy_min << endl;
			
			//cout << "最小整数X" << ansx_min << endl;
			//cout << "最小整数Y" << ansy_min << endl;
			
			printf("%d %d \n", ansx_min, ansy_min);
			
			//cout << ansx_min << ' ' << ansy_min;
		}
	} 
	
	
	//if(check(ansx, ansy))
	
	return 0;
}
