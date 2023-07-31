#include<iostream>
#include <cmath>

using namespace std;

int main()
{
    int n;
    cin>>n;
    float sum;
    for(int i = 1; i <= n; i++)
    {
        if(i > 400)
            sum += 0.5663f;
        else if(i > 150)
            sum += 0.4663f;
        else if(i > 0)
            sum += 0.4463f;
    }
	float ans = round(sum * 10) / 10.0;
    cout<<ans;
    return 0;
}
