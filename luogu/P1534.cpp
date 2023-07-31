#include<iostream>

using namespace std;

int day[3001][2];
int main()
{
    int n;
    cin>>n;
	int ans = 0;
	int sum = 0;
	for(int i = 0; i < n; i++)
	{
		cin>>day[i][0]>>day[i][1];
		sum += day[i][1] + day[i][0] - 8;
    	ans += sum;
    }
	cout<<ans;
	return 0;
}
