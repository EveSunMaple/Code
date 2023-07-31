#include <conio.h>
#include<iostream>

using namespace std;

int n[40001];
int main()
{
    int N;
    for(int i = 0; i < 200; i++)
    {
        if (_getch() == '\n')
            break;
        else
        {
            n[i] = _getch();
            N++;cout<<'a'; 
        }
    }
    for(int i = 0; i < N * N - N; i++)
    {
        cin>>n[i];
    }
    cout<<N<<' ';
    for(int i = 0, v = 0, ans = 0, sum = 0; i < 40001; i++)
    {
        if(ans == n[i])
        {
            sum++;
        }
        else
        {
            ans = n[i];
            cout<<sum<<' ';
            sum = 0;
        }
    }
    return 0;
}
