#include<iostream>

using namespace std;

int main()
{
    float s, x;
    cin>>s>>x;
    float sum = 0;
    for(float i = 7, j = 1; ; j++)
    {
        if(sum >= s - x)
        {
            if(sum + i <= s + x)
        	    cout<<'y';
            else
                cout<<'n';
			break;
		}
        sum += i;
        i = i * 98 / 100;
    }
    return 0;
}