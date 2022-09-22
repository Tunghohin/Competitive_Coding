#include <iostream>
#include <vector>

using namespace std;
using LL = long long;

const int N = 500010;

vector<int> G[N];
int val[N];
int sz[N];
LL dp[N][110];

void dfs(int u)
{
	sz[u] = 0;
	static LL tmp[110];

	for (auto v : G[u])
	{
		dfs(v);

		for (int i = 0; i <= 100 && i <= sz[u] + sz[v]; i++) tmp[i] = -0x3f3f3f3f;

		for (int i = 0; i <= 100 && i <= sz[u]; i++)
		{
			for (int j = 0; i + j <= 100 && j <= sz[v]; j++)
			{
				tmp[i + j] = max(tmp[i + j], dp[u][i] + dp[v][j]);
			}
		}

		for (int i = 0; i <= 100 && i <= sz[u] + sz[v]; i++) dp[u][i] = tmp[i];
		sz[u] += sz[v];
	}

	sz[u]++;
	for (int i = min(sz[u], 100); i >= 1; i--) dp[u][i] = dp[u][i - 1] + val[u];
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
		int a, b;
		cin >> a >> b;

		cout << dp[a][b] << '\n';
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	solve();
}