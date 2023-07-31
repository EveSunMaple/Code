#include<iostream>
#include<cstring>
#include<cstdio>

using namespace std;

int main()
{
	long long a = 0, b = 0;
	cin >> a >> b;
	
	int cnt, num, t = -1;
	
	if(a < b)
	{
		cnt = b / a;
		//cout << cnt << endl;
		num = b - cnt * a;
		//cout << num << endl;
		t = (a - 1) / num;
		if((a - 1) % num == 0)
		{
			cout << cnt * t + 1;
		}
		else
		{
			for(int i = 0; ; i++)
			{
				if(a % b == 1)
				{
					cout << i * cnt * t + 1;
					return 0;
				}
				a += t;
			}
		}
		
		return 0;
	}

	if(a > b)
	{
		for(long long i = 1; ; i++)
		{
			if((i * a) % b == 1)
			{
				cout << i;
				break;
			}
		}
	
		return 0;
	}
	//int cnt = 2;
	
	//for(long long i = 0; ; i += (((b * cnt) - (i * a + num)) / a + 1), cnt++)
	//{
	//	if((i * a + num) % b == 1)
	//	{
	//		cout << i + (b / a) + 1;
	//		break;
	//	}
	//}
	
	return 0;
}
