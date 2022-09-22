#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using LL = long long;

const int N = 2010;

int val[N];
int sz[N];
long long dp[N][N];
vector<int> G[N];

void dfs(int u)
{
	sz[u] = 0;
	static LL tmp[N];

	for (auto v : G[u])
	{
		dfs(v);

		for (int i = 0; i <= sz[u] + sz[v]; i++) tmp[i] = 0x3f3f3f3f;

		for (int i = 0; i <= sz[u]; i++)
		{
			for (int j = 0; j <= sz[v]; j++)
			{
				tmp[i + j] = max(tmp[i + j], dp[u][i] + dp[v][j]);
			}
		}

		for (int i = 0; i <= sz[u] + sz[v]; i++) dp[u][i] = tmp[i];
		sz[u] += sz[v];
	}

	sz[u]++;
	for (int i = sz[u]; i >= 1; i--) dp[u][i] = dp[u][i - 1] + val[u];
	dp[u][0] = 0;
}

void solve()
{
	int n, q;
	cin >> n >> q;

	for (int i = 2; i <= n; i++)
	{
		int x;
		cin >> x;
		G[x].push_back(i);
	}

	for (int i = 1; i <= n; i++) cin >> val[i];

	dfs(1);

	for (int i = 1; i <= q; i++)
	{
		int x, y;
		cin >> x >> y;
		cout << dp[x][y] << '\n';
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	solve();
} 