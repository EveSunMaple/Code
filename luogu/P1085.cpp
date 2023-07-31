#include<iostream>

using namespace std;

int main()
{
	int day[7][3];
	for(int i = 0; i < 7; i++)
	{
		cin>>day[i][0]>>day[i][1];
		day[i][2] = day[i][1] + day[i][0] - 8;
	}
	int ans = 0;
	int sum = 0;
	for(int i = 0; i < 7; i++)
	{
		if(day[i][2] > sum)
		{
			sum = day[i][2];
			ans = i + 1;
		}
	}
	cout<<ans;
	return 0;
}