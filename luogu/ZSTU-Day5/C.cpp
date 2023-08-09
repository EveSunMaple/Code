#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

int a[10] = {0, 9, 3, 5, 2, 1, 4, 7, 8, 6};
int N = 9;

void out()
{
    printf("NOW : \n");
    for (int i = 1; i <= N; i++)
        printf("%d ", a[i]);
    printf("\n");
}

void Qsort(int a[], int low, int high)
{
    if (low >= high)
        return;
    int first = low;
    int last = high;
    int key_index = (rand() % (high - low + 1)) + low;
    swap(a[first], a[key_index]);
    int key = a[first]; /*用数组的第一个记录作为中枢*/ out();
    while (first < last)
    {
        while (first < last && a[last] >= key) --last;
        a[first] = a[last]; /*将比第一个小的移到低端*/ out();
        while (first < last && a[first] <= key) ++first;
        a[last] = a[first]; /*将比第一个大的移到高端*/ out();
    }
    a[first] = key; /*中枢记录到位*/ out();
    Qsort(a, low, first - 1);
    Qsort(a, first + 1, high);
}

int main()
{
    int n, k;
    scanf("%d%d", &n, &k);
    for (int i = 1, t = 0; i <= k; i++) scanf("%d", &t);
    for (int i = 1; i <= n; i++) printf("%d\n", i);
    return 0;
}