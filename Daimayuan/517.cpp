#include <iostream>

using namespace std;

int cnt = 0;
int p[50000010], primes[50000010];

void linear_sieve(int n)
{
	for (int i = 2; i <= n; i++)
	{
		if (!p[i]) p[i] = i, primes[++cnt] = i;
		for (int j = 1; j <= cnt && primes[j] * i <= n; j++)
		{
			p[i * primes[j]] = primes[j];
			if (p[i] == primes[j]) break;
		}
	}
}

void solve()
{
	int n;
	unsigned int a, b;
	cin >> n >> a >> b;

	linear_sieve(n);

	unsigned int res = 0;
	for (int i = 1; i <= cnt; i++)
	{
		res = res ^ (a * primes[i] + b);
	}

	cout << res;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	solve();
}