#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>

const int N = 10005;
int n, x[N], y[N], w[N];
double ansx, ansy, dis;

double Rand() { return (double)rand() / RAND_MAX; }

double calc(double nowx, double nowy)
{
    double res = 0;
    for (int i = 1; i <= n; ++i)
    {
        double dx = x[i] - nowx;
        double dy = y[i] - nowy;
        res += sqrt(dx * dx + dy * dy); // 勾股定理
    }
    if (res < dis) // 如果当前的值比dis更加优秀，直接更新此值
        dis = res, ansx = nowx, ansy = nowy;
    return res;
}

void solve()
{
    double t = 20000;
    double nowx = ansx, nowy = ansy;
    while (t > 0.001)
    {
        double nxtx = nowx + t * (Rand() * 2 - 1);
        double nxty = nowy + t * (Rand() * 2 - 1);
        double delta = calc(nxtx, nxty) - calc(nowx, nowy);
        if (exp(-delta / t) > Rand())
            nowx = nxtx, nowy = nxty;
        t *= 0.997;
    }
    for (int i = 1; i <= 1000; ++i)
    {
        // 最后在附近跳值
        double nxtx = ansx + t * (Rand() * 2 - 1);
        double nxty = ansy + t * (Rand() * 2 - 1);
        calc(nxtx, nxty);
    }
}

int main()
{
    srand(0); 
    int t;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i)
        {
            scanf("%d%d%d", &x[i], &y[i], &w[i]);
            ansx += x[i], ansy += y[i];
        }
        ansx /= n, ansy /= n; // 算出当前的平均坐标当作起始点
        dis = calc(ansx, ansy); // 算出当前起始点的总值
        solve();
        printf("%d\n", dis);
    }
    return 0;
}
