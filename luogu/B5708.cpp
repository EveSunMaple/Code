#include<iostream>
#include<iomanip>
#include<math.h>

using namespace std;

int main()
{
    double a, b, c;
    cin>>a>>b>>c;
    cout<<fixed<<setprecision(1);
    double p = (a + b + c) / 2;
    cout<<sqrt(p * (p - a) * (p - b) * (p - c));
	return 0;
}