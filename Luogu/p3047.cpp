#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#define int long long

using namespace std;
using LL = long long;

const int N = 100010;

int n, k;
int val[N];
int dp[N][30];
vector<int> G[N];

void dfs_1(int u, int from)
{
	for (int i = 0; i <= k; i++)
	{
		dp[u][i] = val[u];
	}
	for (auto v : G[u])
	{
		if (v == from) continue;
		dfs_1(v, u);

		for (int i = 1; i <= k; i++)
		{
			dp[u][i] += dp[v][i - 1];
		}
	}
}

void dfs_2(int u, int from)
{
	for (auto v : G[u])
	{
		if (v == from) continue;

		for (int i = k; i >= 1; i--)
		{
			if (i == 1) dp[v][i] += dp[u][0];
			else dp[v][i] += dp[u][i - 1] - dp[v][i - 2];
		}
		dfs_2(v, u);
	}
}

void solve()
{
	cin >> n >> k;

	for (int i = 1; i < n; i++)
	{
		int u, v;
		cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}

	for (int i = 1; i <= n; i++)
	{
		cin >> val[i];   
	}

	dfs_1(1, 0);

	dfs_2(1, 0);

	for (int i = 1; i <= n; i++)
	{
		cout << dp[i][k] << '\n';
	}
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	solve();
}