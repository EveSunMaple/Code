#include <unordered_map>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <time.h>
#define N 20000

using namespace std;

int main()
{
    rand();
	freopen("C.in", "w", stdout);
    int t = 3;
    printf("%d\n", t);
    while (t--)
    {
        int n = rand() % N;
        printf("%d\n", n);
        unordered_map<int, int> hash;
        for (int i = 1; i <= n;)
        {
            int temp = rand();
            if (hash[temp]) continue;
            printf("%d ", temp);
            hash[temp] = 1;
            i++;
        }
        printf("\n");
        for (int i = 1; i < n;)
        {
            int temp = rand();
            if (hash[temp]) continue;
            printf("%d ", temp);
            hash[temp] = 1;
            i++;
        }
        printf("0\n");
    }
    
    return 0;
}
