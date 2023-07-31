#include<iostream>

using namespace std;

int main()
{
    float s;
    cin>>s;
    float sum = 0;
    int ans = 0;
    for(float i = 2, j = 1; ; j++)
    {
        sum += i;
        i = i * 98 / 100;
        if(sum > s)
        {
        	ans = j;
			break;
		}
    }
    cout<<ans;
    return 0;
}
