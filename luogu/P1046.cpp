#include<iostream>

using namespace std;

int main()
{
	int sum = 0;
	int p[10];
	for(int i = 0; i < 10 ; i++)
	{
		cin>>p[i];
	}
	int t;
	cin>>t;
	for(int i = 0; i < 10; i++)
	{
		if(t + 30 >= p[i])
			sum++;
	}
	cout<<sum;
	return 0;	
}
