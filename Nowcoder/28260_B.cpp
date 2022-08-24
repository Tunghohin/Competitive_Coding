#include <iostream>
#include <vector>

using namespace std;

const int N = 100010;

int res = 0;
int n;
int val[N];
int dp[N];
vector<int> G[N];

void dfs(int u)
{
	for (auto v : G[u])
	{
		dfs(v);
		val[u] = max(val[u], val[v] - 1);
		dp[u] = max(dp[u], dp[v] - 1);
	}

	if (!dp[u])
	{
		++res;
		dp[u] = val[u];
	}
}

void solve()
{
	cin >> n;
	for (int i = 2; i <= n; i++)
	{
		int x;
		cin >> x;
		G[x].push_back(i);
	}

	for (int i = 1; i <= n; i++) cin >> val[i];

	dfs(1);
	cout << res << '\n';
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	solve();
}