#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> G[1010];
int sz[1010], dp[1010];

void dfs(int u, int from)
{
	sz[u] = 1;
	for (auto v : G[u])
	{
		if (v == from) continue;
		dfs(v, u);
		sz[u] += sz[v];
	}

	dp[u] = n - sz[u];
	for (auto v : G[u])
	{
		dp[u] = max(dp[u], sz[v]);
	}
}

void solve()
{
	cin >> n;

	for (int i = 1; i < n; i++)
	{
		int a, b;
		cin >> a >> b;
		G[a].push_back(b);
		G[b].push_back(a);
	}

	dfs(1, 0);

	int node = 0;
	int res = 0x3f3f3f3f;
	for (int i = 1; i <= n; i++)
	{
		if (dp[i] < res)
		{
			res = dp[i];
			node = i;
		}
	}

	cout << node << ' ' << res << '\n';
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	solve();
}