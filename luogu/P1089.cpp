#include<iostream>

using namespace std;

int main()
{
	int d[12];
	int m = 0;
	int sum = 0;
	for(int i = 0; i < 12; i++)
	{
		cin>>d[i];
	}
	for(int i = 0; i < 12; i++)
	{
		m += 300 - d[i];
		if(m < 0)
		{
			cout<<-i - 1;
			return 0;
		}
		else
		{
			for(int j = 0; j < 10001; j++)
			{
				if(j * 100 > m)
				{
					m -= j * 100 - 100;
					sum += j * 100 - 100;
					break;
				}
			}
		}
	}
	int ans = m + sum / 5 * 6;
	cout<<ans;
	return 0;
}