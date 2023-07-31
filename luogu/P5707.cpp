#include<iostream>

using namespace std;

int main()
{
	int s, v;
	cin>>s>>v;
	int t = s / v;
	if(s % v != 0)
		t++;
	int ans = 470;
	ans -= t;
	if(ans < 0)
		ans += 1440;
	if(ans / 60 < 10)
		cout<<"0";
	cout<<ans / 60;
	cout<<":";
	if(ans % 60 != 0)
	{
		if(ans % 60 < 10)
			cout<<"0";
		cout<<ans % 60;
	}
	else
		cout<<"00";
        return 0;
}