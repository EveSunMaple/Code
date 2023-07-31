#include <iostream>
#include <cmath>
#include <cstdio>

using namespace std;

int main()
{
    freopen("1.txt", "w", stdout);
    for(int i = 0; i < 100; i++)
        for(int j = 0; j < 100; j++)
        {
            if(i % 2)
                printf("%d ", i * 100 + j);
            else
                printf("%d ", i * 100 + (100 - j));
        }

    return 0;
}