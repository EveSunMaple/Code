#include<iostream>

using namespace std;

int main()
{
	char a[5];
    for(int i = 0; i < 5; i++)
    {
        a[i] = getchar();
    }
    for(int i = 4; i >= 0; i--)
    {
        cout<<a[i];
    }
}