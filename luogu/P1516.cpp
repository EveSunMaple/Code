#include<iostream>

using namespace std;

int d = 0; //gcd(L, (m - n))

int gcd(long long l, long long r, long long &a, long long &b)
{
	if(r == 0)
	{
		a = 1, b= 0;
		return l;
	}
	
	long long d = gcd(r, l % r, a, b);
	
	long long z = a;
	a = b;
	b = z - (l / r) * b;
	
	return d;
} 

int main()
{
	long long x = 0, y = 0;
	long long n = 0, m = 0;
	long long L = 0;
	
	long long a = 0; //JumpNum
	long long b = 0; //Num
	
	cin >> x >> y >> n >> m >> L;
	
	//求bL + a(m - n) = x - y的最小特解 
	
	d = gcd((m - n), L, a, b);
	
	if((x - y) % d)	//SP
	{
		cout << "Impossible";
		return 0;
	}
	
	a *= (x - y) / d;
	b *= (x - y) / d;

	if(L / d > 0)
	{
        if(a > 0)
        {
            int i = a / (L / d);
            cout << a - (L / d) * i;

            return 0;
        }
        else
        {
            int i = -a / (L / d);
            cout << a + (L / d) * (i + 1);

            return 0;
        }
	}
    else
	{
        if(a > 0)
        {
            int i = a / (-(L / d));
            cout << a - (-(L / d)) * i;

            return 0;
        }
        else
        {
            int i = -a / (-(L / d));
            cout << a + (-(L / d)) * (i + 1);

            return 0;
        }
	}
}