#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;
using LL = long long;

const int N = 1010;

int n, p;

int sz[N];
int dp[N][N];
int ans = 0x3f3f3f3f;
vector<int> G[N];

void dfs(int u, int from)
{
	dp[u][0] = 0;
	for (auto v : G[u])
	{
		if (v == from) continue;
		dfs(v, u);

		sz[u] += sz[v];
	}

	sz[u]++;
	dp[u][0] = 0, dp[u][sz[u]] = 1;
	if (u == 1) dp[1][sz[u]] = 0;
	for (auto v : G[u])
	{
		if (v == from) continue;

		for (int j = sz[u] - 1; j; j--)
		{
			for (int k = 0; k <= j; k++)
			{
				dp[u][j] = min(dp[u][j], dp[u][j - k] + dp[v][k]);
			}
		}
	}
	if (sz[u] >= p)
	{
		ans = min(ans, dp[u][sz[u] - p] + dp[u][sz[u]]);
	}
}

void solve()
{
	cin >> n >> p;

	for (int i = 2; i <= n; i++)
	{
		int u, v;
		cin >> u >> v;
		G[u].push_back(v);
	}

	memset(dp, 0x3f, sizeof(dp));

	dfs(1, 0);
	cout << ans << '\n';
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	solve();
}