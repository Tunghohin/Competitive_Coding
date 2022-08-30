#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;
using LL = long long;

const int MOD = 1e9 + 7;
const int N = 100010;

vector<int> G[N];
int color[N];
LL dp[N][5];

void dfs(int u, int from)
{
	for (auto v : G[u])
	{
		if (v == from) continue;
		dfs(v, u);

		for (int i = 1; i <= 3; i++)
		{
			if (i == 1)
			{
				dp[u][i] = dp[u][i] * (dp[v][2] + dp[v][3]) % MOD;
			}
			else if (i == 2)
			{
				dp[u][i] = dp[u][i] * (dp[v][1] + dp[v][3]) % MOD;
			}
			else
			{
				dp[u][i] = dp[u][i] * (dp[v][1] + dp[v][2]) % MOD;
			}
		}
	}
}

void solve()
{
	int n, k;
	cin >> n >> k;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= 3; j++) dp[i][j] = 1;
	}

	for (int i = 1; i < n; i++)
	{
		int u, v;
		cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}

	for (int i = 1; i <= k; i++)
	{
		int a, b;
		cin >> a >> b;
		for (int j = 1; j <= 3; j++)
		{
			if (j != b) dp[a][j] = 0;
		}
	}

	dfs(1, 0);

	LL res = 0;
	for (int i = 1; i <= 3; i++) res = res + dp[1][i] % MOD;

	cout << res % MOD << '\n';
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	solve();
}