#include<iostream>
#include<iomanip>

using namespace std;

int main()
{
    long long x, a, y, b;
	double z;

	cin >> x >> a >> y >> b;

	z = (a * x - b * y) / (a - b);

    cout<< fixed << setprecision(2) << z <<endl;

    return 0;
}