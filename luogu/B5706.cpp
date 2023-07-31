#include<iostream>
#include<iomanip>

using namespace std;

int main()
{
    float t;
	int n;
    cin>>t>>n;
    cout<<fixed<<setprecision(3);
    cout<<(float)(t / n)<<endl;
    cout<<n * 2;
	return 0;
}