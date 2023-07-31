#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MaxN = 1005;

int n, k, a[MaxN], f[MaxN][MaxN], g[MaxN][MaxN], f_[MaxN][MaxN];

// cmin �������ڸ��� x ����Сֵ
inline bool cmin(int &x, int y) {
    return x > y ? x = y, true : false;
}

// transition �������ڽ���һ��ת��
void transition() {
    // �� f_ �����ʼ��Ϊһ���ܴ��ֵ
    memset(f_, 0x3f, sizeof(f_));
    // ��ʼ�� g ����ĶԽ���Ԫ��
    for (int i = 1; i <= n; i++)
        g[i][i] = i;
    // ö�����䳤�� h
    for (int h = 1; h <= n; h++) {
        // ö��������˵� l
        for (int l = 1; l + h <= n; l++) {
            // ���������Ҷ˵� r
            int r = l + h;
            // ö�پ��ߵ� x
            for (int x = g[l][r - 1]; x <= g[l + 1][r]; x++) {
                // ����״̬ f_[l][r] �����ž��ߵ� g[l][r]
                if (cmin(f_[l][r], f[l][x] + f[x + 1][r] + abs(a[x] - a[r])))
                    g[l][r] = x;
            }
        }
    }
    // �� f_ �����е�ֵ���µ� f ������
    for (int i = 1; i <= n; i++)
        for (int j = i; j <= n; j++)
            cmin(f[i][j], f_[i][j]);
}

int main() {
    // ��������
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    // ��ս��ֵ��С��������
    sort(a + 1, a + n + 1);
    // �� f �����ʼ��Ϊһ���ܴ��ֵ
    memset(f, 0x3f, sizeof(f));
    // ���Խ����ϵ�Ԫ�س�ʼ��Ϊ 0
    for (int i = 1; i <= n; i++)
        f[i][i] = 0;
    // ���� k ��ת��
    while (k--)
        transition();
    // �����
    cout << f[1][n] << "\n";
    return 0;
}
