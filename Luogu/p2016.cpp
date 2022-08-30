#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
using LL = long long;

const int N = 1510;

LL dp[N][2];
vector<int> G[N];

void dfs(int u)
{
	dp[u][0] = 0;
	dp[u][1] = 1;

	for (auto v : G[u])
	{
		dfs(v);

		dp[u][0] += dp[v][1];
		dp[u][1] += min(dp[v][0], dp[v][1]);
	}
}

void solve()
{
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		int p, s_cnt;
		cin >> p >> s_cnt;
		while (s_cnt--)
		{
			int x;
			cin >> x;
			G[p].push_back(x);
		}
	}

	dfs(0);

	cout << min(dp[0][0], dp[0][1]) << '\n';
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	solve();
}