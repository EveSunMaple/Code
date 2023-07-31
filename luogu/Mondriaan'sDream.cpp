#include <algorithm>
#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

long long v[1 << 11];
long long f[1 << 11];

int main()
{
    int h = 1, w = 1;
    for(; ;)
    {
        cin >> h >> w;
        if(h == 0 && w == 0) break;
        f[0] = 1;
        for(int y = 1; y <= h; y++)
        {
            for(int x = 1; x <= w; x++)
            {
                memset(v, 0, sizeof(v));
                for(int k = 0; k < (1 << w); k++)
                {
                    if(k & (1 << (x - 1)))
                        v[k ^ (1 << (x - 1))] += f[k];
                    else
                    {
                        if(x < w && !(k & (1 << x)))
                            v[k ^ (1 << x)] += f[k];
                        if(y < h)
                            v[k ^ (1 << (x - 1))] += f[k];
                    }
                }
                memcpy(f, v, sizeof(v));
            }
        }
        printf("%lld\n", f[0]);
    }

    return 0;
}