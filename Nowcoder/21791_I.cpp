#include <bits/stdc++.h>

using namespace std;
using LL = long long;
using ULL = unsigned long long;
using PII = pair<int, int>;
using PLI = pair<long long, int>;
using PLL = pair<long long, long long>;

const int N = 1000005, M = 5005;

int f[M][M];
vector<LL> g[N];
LL dp[N];
LL fact_up[N], fact_dw[N];
int l[N];

void solve()
{
	int n, m, MOD;
	cin >> n >> m >> MOD;

	for (int i = 1; i <= n; i++)
	{
		cin >> l[i];
		g[i].resize(l[i] + 1);
	}

	f[0][0] = 1;
	for (int i = 1; i <= 5000; i++)
	{
		for (int j = 1; j <= 5000; j++)
		{
			f[i][j] = ((LL)f[i - 1][j - 1] + (LL)(j - 1) * f[i - 1][j] % MOD) % MOD;
		}
	}

	fact_dw[0] = fact_up[0] = 1;
	for (int i = 1; i <= m; i++)
	{
		fact_up[i] = ((LL)fact_up[i - 1] * (LL)(m - i + 1)) % MOD;
		fact_dw[i] = ((LL)fact_dw[i - 1] * (LL)i) % MOD;
	}

	for (int i = 1; i <= min(l[1], m); i++)
	{
		g[1][i] = f[l[1]][i];
		dp[1] = ((LL)dp[1] + (LL)g[1][i] * fact_up[i] % MOD) % MOD;
	}
	for (int i = 2; i <= n; i++)
	{
		for (int j = 1; j <= min(l[i], m); j++)
		{
			if (l[i - 1] >= j)
			{
				g[i][j] = ((LL)f[l[i]][j] * 1ll * (dp[i - 1] - 1ll * (g[i - 1][j] * fact_dw[j]) % MOD + MOD) % MOD) % MOD;
			}
			else g[i][j] = ((LL)f[l[i]][j] * dp[i - 1]) % MOD;
			dp[i] = (dp[i] + g[i][j] * fact_up[j]) % MOD;
		}
	}

	cout << dp[n] % MOD;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int T;
	T = 1;

	while (T--)
	{
		solve();
	}
}