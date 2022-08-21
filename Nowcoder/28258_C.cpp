#include <cstdio>
#include <vector>
#include <iostream>

using namespace std;

const int N = 1502;

int n;
int dp[N][2];
vector<int> G[N];

void dfs(int u, int from)
{
	dp[u][0] = 0;
	dp[u][1] = 1;
	for (auto v : G[u])
	{
		if (v == from) continue;
		dfs(v, u);
		dp[u][1] += min(dp[v][0], dp[v][1]);
		dp[u][0] += dp[v][1];
	}
}

void solve()
{
	for (int i = 0; i <= n; i++) G[i].clear();

	for (int i = 1; i <= n; i++)
	{
		int f, sz;
		scanf("%lld:(%lld) ", &f, &sz);

		for (int j = 1; j <= sz; j++)
		{
			int s;
			cin >> s;

			G[f].push_back(s);
			G[s].push_back(f);
		}
	}

	dfs(0, -1);
	cout << min(dp[0][0], dp[0][1]) << '\n';
}

int main()
{
	while (cin >> n) 
	{
		solve();
	}
}