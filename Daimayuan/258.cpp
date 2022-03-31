#include <iostream>

using namespace std;

const int N = 2010;

long long dp[N][2 * N];
long long inv[2 * N];
const long long mod = 998244353;

int q_pow(long long a, long long k)
{
	long long res = 1;
	while (k)
	{
		if (k & 1)
		{
			res = res * a % mod;
		}
		a = a * a % mod;
		k >>= 1;
	}

	return res;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int n;
	cin >> n;

	for (int i = 1; i <= 2 * n; i++)
	{
		inv[i] = q_pow(i, mod - 2);
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j <= 2 * n - 2; j++)
		{
			dp[i][j] = dp[i - 1][j + 2] * i % mod * inv[j + i] % mod;
			if (j)
			{
				dp[i][j] += dp[i][j - 1] * j % mod * inv[j + i] % mod;
			}
			dp[i][j] += 1;
		}
	}

	cout << dp[n][0];
}