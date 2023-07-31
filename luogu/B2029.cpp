#include<iostream>

using namespace std;

int main()
{
	int h, r;
    cin>>h>>r;
    double sum = (double)(r * r) * 3.14 * (double)h;
    int ans = (double)20000 / sum + 1;
    cout<<ans;
	return 0;
}