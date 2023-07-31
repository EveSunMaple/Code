#include <cstdio>
#include <iostream>
using namespace std;

typedef long long LL;
const int N = 100005;

LL w[N];
LL fac[N], inv[N];
LL p[N], c[N], cntP, cnt, a0, a1, m0, m1, P, mo;
int n, m, ID;

LL power(LL x, LL y, LL M)
{
	LL ans = 1;
	for (; y > 0; y >>= 1) {
		if (y & 1) {
			ans *= x;
			if (M != -1) ans %= M;
		}
		x *= x;
		if (M != -1) x %= M;
	}
	return ans;
}

LL calcfac(LL n)
{
	if (n < p[ID]) return fac[n];
	LL seg = n / P, rem = n % P;
	LL ret = power(fac[P - 1], seg, P);
	ret = ret * fac[rem] % P;
	cnt += n / p[ID];
	ret = ret * calcfac(n / p[ID]) % P;
	return ret;
}

LL calcinv(LL n)
{
	if (n < p[ID]) return inv[n];
	LL seg = n / P, rem = n % P;
	LL ret = power(inv[P - 1], seg, P);
	ret = ret * inv[rem] % P;
	cnt -= n / p[ID];
	ret = ret * calcinv(n / p[ID]) % P;
	return ret;
}

LL exgcd(LL a, LL b, LL &x, LL &y)
{
	if (b == 0) {
		x = 1; y = 0;
		return a;
	} else {
		LL r = exgcd(b, a % b, y, x);
		y -= a / b * x;
		return r;
	}
}

LL getinv(LL i, LL P)
{
	LL x, y;
	exgcd(i, P, x, y);
	x %= P;
	x += (x < 0) * P;
	return x;
}

LL solve()
{
	P = power(p[ID], c[ID], -1);
	fac[0] = 1;
	for (int i = 1; i < P; ++i) {
		fac[i] = fac[i - 1];
		if (i % p[ID] != 0)
			fac[i] = fac[i] * i % P;
	}
	inv[0] = 1;
	for (int i = 1; i < P; ++i) {
		inv[i] = inv[i - 1];
		if (i % p[ID] != 0)
			inv[i] = inv[i] * getinv(i, P) % P;
	}
	cnt = 0;
	LL ret = calcfac(n);
	//cout << ret << " " << cnt << endl;
	for (int i = 1; i <= m; ++i) {
		ret = ret * calcinv(w[i]) % P;
		//cout << w[i] << " " << ret << " " << cnt << endl;
	}
	ret = ret * power(p[ID], cnt, P) % P;
	return ret;
}

void solve_equation(LL a, LL b, LL c, LL &k, LL &l)
{
	exgcd(a, b, k, l);
	k *= c;
	k %= b;
	k += (k < 0) * b;
	return;
}

int main()
{
	freopen("reword.in", "r", stdin);
	freopen("reword.out", "w", stdout);
	cin>>n>>m>>mo;
	for (int i = 2; i < 100000; ++i) if (mo % i == 0) {
		p[++cntP] = i;
		for (; mo % i == 0; mo /= i) ++c[cntP];
	}
	w[1]=n,w[2]=m;
	n=n+m;
	m=2;
	LL sw = 0;
	for (int i = 1; i <= m; ++i) sw += w[i];
	if (n - sw > 1) w[++m] = n - sw;
	for (int i = 1; i <= cntP; ++i) {
		ID = i;
		a1 = solve();
		m1 = power(p[i], c[i], -1);
		if (i == 1) {
			a0 = a1;
			m0 = m1;
		} else {
			LL k, l;
			solve_equation(m0, m1, a1 - a0, k, l);
			a0 = a0 + k * m0;
			m0 *= m1;
		}
	}
	printf("%d\n", a0);
	return 0;
}
