#include<iostream>

using namespace std;

int main()
{
	double S = 0.00000000;
	double k;
	cin >> k;
	for (int i = 1; i < 1000000; i++)
	{
		S = S + (double)1 / i;
		if (S > k)
		{
			cout << i <<endl;
			break;
		}
	}
	return 0;
}
