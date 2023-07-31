#include<iostream>

using namespace std;

int main()
{
    int x, n;
    cin>>x>>n;
    int sum = 0;
    x--;
    for(int i = 0; i < n; i++)
    {
        x++;
        if(x == 8)
        {
            x = 1;
        }
        if(x <= 5)
        {
            sum += 250;
        }
    }
    cout<<sum;
    return 0;
}
