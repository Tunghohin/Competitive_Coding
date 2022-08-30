#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int N = 100010;

int dp[N][3]; //0select 1child 2parent
vector<int> G[N];

void dfs(int u, int from)
{
	dp[u][0] = 1;
	dp[u][1] = 0;
	dp[u][2] = 0;
	bool has_child = false;
	bool flag = false;
	int min_dif = 0x3f3f3f3f;
	for (auto v : G[u])
	{
		if (v == from) continue;

		dfs(v, u);

		has_child = true;
		dp[u][0] += min({dp[v][0], dp[v][1], dp[v][2]});
		dp[u][2] += min(dp[v][0], dp[v][1]);
		if (dp[v][0] <= dp[v][1])
		{
			flag = true;
			dp[u][1] += dp[v][0];
		}
		else
		{
			dp[u][1] += dp[v][1];
			min_dif = min(min_dif, dp[v][0] - dp[v][1]);
		}
	}
	if (!has_child) dp[u][1] = 0x3f3f3f3f;
	if (!flag) dp[u][1] += min_dif;
}

void solve()
{
	int n;
	cin >> n;

	for (int i = 1; i < n; i++)
	{
		int a, b;
		cin >> a >> b;
		G[a].push_back(b);
		G[b].push_back(a);
	}

	dfs(1, 0);

	cout << min(dp[1][0], dp[1][1]);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	solve();
}