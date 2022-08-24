#include <iostream>
#include <vector>

using namespace std;
using LL = long long;

const int inf32 = 0x3f3f3f3f;
const int N = 310;

int n, m;
LL dp[N][N];
int val[N];
int sz[N];
vector<int> G[N];

void dfs(int u)
{
	sz[u] = 0;
	static LL tmp[N];

	for (auto v : G[u])
	{
		dfs(v);
		for (int i = 0; i <= sz[u] + sz[v]; i++) tmp[i] = -inf32;

		for (int i = 0; i <= sz[u]; i++)
		{
			for (int j = 0; j <= sz[v]; j++)
			{
				tmp[i + j] = max(dp[u][i] + dp[v][j], tmp[i + j]);
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
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		int x, v;
		cin >> x >> v;
		G[x].push_back(i);
		val[i] = v;
	}

	dfs(0);

	cout << dp[0][m + 1];
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	solve();
}