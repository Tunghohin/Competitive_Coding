#include <iostream>

using namespace std;
using LL = long long;

const int MOD = 1e9 + 7;
const int N = 1000010;

int fact[N], inv[N];

int q_pow(int a, int k)
{
	int res = 1;
	while (k)
	{
		if (k & 1) res = ((LL)res * a % MOD) % MOD;
		a = ((LL)a * a) % MOD;
		k >>= 1;
	}
	return res;
}

int C(int x, int y)
{
	if (x < y) return 0;
	return ((LL)((LL)fact[x] * inv[x - y]) % MOD * inv[y]) % MOD;
}

void solve()
{
	int a, b, n;
	cin >> a >> b >> n;

	int res = 0;
	for (int i = 0; i <= n; i++)
	{
		bool flag = true;
		LL num = i * a + (n - i) * b;
		while (num)
		{
			if (num % 10 != a && num % 10 != b)
			{
				flag = false;
				break;
			}
			num /= 10;
		}

		if (flag)
		{
			res = (res + C(n, i)) % MOD;
		}
	}
	cout << res << '\n';
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	fact[0] = inv[0] = 1;
	for (int i = 1; i <= N - 10; i++)
	{
		fact[i] = ((LL)fact[i - 1] * i) % MOD;
		inv[i] = q_pow(fact[i], MOD - 2);
	}

	solve();
}