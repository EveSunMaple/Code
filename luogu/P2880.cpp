#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

unsigned Log2(unsigned x)
{
    x |= x >> 1;
    x |= x >> 2;
    x |= x >> 4;
    x |= x >> 8;
    x |= x >> 16;
    return log2(x) + 0.5;
}

int main()
{
    
    return 0;
}