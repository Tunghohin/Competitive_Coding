#include <iostream>
#include <vector>

using namespace std;

const int N = 6010;

int val[N];
int dp[N][2];
int in_d[N];
vector<int> G[N];

void dfs(int u)
{
	dp[u][0] = 0;
	dp[u][1] += val[u];
	for (auto v : G[u])
	{
		dfs(v);

		dp[u][0] += max(dp[v][1], dp[v][0]);
		dp[u][1] += dp[v][0];
	}
}

void solve()
{
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) cin >> val[i];

	for (int i = 1; i < n; i++)
	{
		int a, b;
		cin >> a >> b;
		G[b].push_back(a);
		in_d[a]++;
	}

	for (int i = 1; i <= n; i++)
	{
		if (in_d[i] == 0)
		{
			dfs(i);
			cout << max(dp[i][0], dp[i][1]) << '\n';
			return;
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	solve();
}