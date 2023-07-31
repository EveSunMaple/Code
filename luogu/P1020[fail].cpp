#include <iostream>
#include <cstdio>

using namespace std;

int limit = 0;
int Mi[100005];
int ans[100005];
bool S[100005];

int solve(int crd, int tail)
{
    int len = 0;
    for(int i = limit; i >= 1; i--)
    {
        for(int j = i - 1; j >= 1; j--)
        {
            if(Mi[crd] > Mi[tail] && S[tail] == false)
            {
                solve(tail, tail);
                S[tail] = true;
            }
        }
    }
}

int main()
{   
    for(int i = 1; cin >> Mi[i]; i++, limit++);


    return 0;
}