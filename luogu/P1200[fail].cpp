#include<iostream>
#include<string>

using namespace std;

int main()
{
	string a;
	string b;
	cin>>a>>b;
	int suma, sumb;
	suma = sumb = 1;
	for(int i = 0; i < 6; i++)
	{
		if(a[i] != 0)
		{
			suma *= (int)a[i] - 64;
		}
		if(b[i] != 0)
		{
			sumb *= (int)b[i] - 64;
		}
	}
	if(suma % 47 == sumb % 47)
	{
		cout<<"GO";
	}
	else
		cout<<"STAY";
	return 0;
}