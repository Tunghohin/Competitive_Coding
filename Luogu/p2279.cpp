#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int N = 1010;

int n;
int dp[N][5]; //0 pp, 1 p, 2 select, 3 s, 4 ss
vector<int> G[N];

void dfs(int u, int from)
{
	dp[u][0] = 1;

	int sum2 = 0, sum3 = 0;

	bool flag = false;
	for (auto v : G[u])
	{
		if (v == from) continue;
		flag = true;
		dfs(v, u);
		sum2 += dp[v][2];
		sum3 += dp[v][3];
	}

	if (!flag)
	{
		dp[u][0] = dp[u][1] = dp[u][2] = 1;
		return;
	}

	dp[u][0] = 1, dp[u][1] = dp[u][2] = N;
	for (auto v : G[u])
	{
		if (v == from) continue;
		dp[u][0] += dp[v][4];
		dp[u][1] = min(dp[u][1], dp[v][0] + sum3 - dp[v][3]);
		dp[u][2] = min(dp[u][2], dp[v][1] + sum2 - dp[v][2]);
		dp[u][3] += dp[v][2];
		dp[u][4] += dp[v][3];
	}

	for (int i = 1; i <= 4; i++)
	{
		dp[u][i] = min(dp[u][i], dp[u][i - 1]);
	}
}

void solve()
{
	cin >> n;

	for (int i = 2; i <= n; i++)
	{
		int x;
		cin >> x;
		G[i].push_back(x);
		G[x].push_back(i);
	}

	dfs(1, 0);

	cout << dp[1][2] << '\n';
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	solve();
}