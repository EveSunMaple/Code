#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int n, k, a[N];
long long ans;
vector<int> v[N];
int main() {
    scanf("%d%d", &n, &k);
    for(int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        v[i % k].push_back(a[i]);
    }
    for(int i = 0; i < k; i++) sort(v[i].rbegin(), v[i].rend());
    for(int i = 0; i < k; i++) {
        for(int j = 0; j + 1 < v[i].size(); j += 2) {
            ans += v[i][j] + v[i][j+1];
        }
    }
    printf("%lld\n", ans);
    return 0;
}

