#include <iostream>

using namespace std;

typedef long long LL;

const int N = 2010, mod = 100003;

int fact[N], inv_fact[N];

int qmi(int a, int k)
{
	int res = 1;
	while (k)
	{
		if (k & 1) res = (int)((LL)res * a % mod);
		a = (int)((LL)a * a % mod);
		k >>= 1;
	}

	return res;
}

int C(int a, int b)
{
	if (a < b) return 0;
	return (int)((LL)fact[a] * inv_fact[a - b] % mod * inv_fact[b] % mod);
}

int A(int a, int b)
{
	if (a < b) return 0;
	return (int)((LL)fact[a] * inv_fact[a - b] % mod);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int a, b, c, d, k;
	cin >> a >> b >> c >> d >> k;

	fact[0] = inv_fact[0] = 1;
	for (int i = 1; i < N; i++)
	{
		fact[i] = (int)((LL)fact[i - 1] * i % mod);
		inv_fact[i] = (int)((LL)inv_fact[i - 1] * qmi(i, mod - 2) % mod);
	}

	int res = 0;
	for (int i = 0; i <= k; i++)
	{
		res = (int)(res + (LL)C(b, i) * A(a, i) % mod * C(d, k - i) % mod * A(a + c - i, k - i) % mod) % mod;
	}

	cout << res;
}