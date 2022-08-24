#include <iostream>
#include <vector>

using namespace std;

const int inf32 = 0x3f3f3f3f;
const int N = 500010;

int n, s;
int dp[N][2];
vector<int> G[N];

void dfs(int u, int from)
{
	dp[u][1] = 1;
	if (u == s) dp[u][0] = -inf32;
	else dp[u][0] = 0;

	for (auto v : G[u])
	{
		if (v == from) continue;
		dfs(v, u);

		dp[u][0] += max(dp[v][0], dp[v][1]);
		dp[u][1] += dp[v][0]; 
	}
}

void solve()
{
	cin >> n >> s;

	for (int i = 1; i < n; i++)
	{
		int u, v;
		cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}

	dfs(1, 0);
	cout << max(dp[1][0], dp[1][1]);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	solve();
}