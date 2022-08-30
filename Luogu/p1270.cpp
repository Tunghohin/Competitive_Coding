#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 1010;

int limit;
int t[N], val[N];
long long dp[N][N];

void read(int u)
{
	cin >> t[u] >> val[u];
	t[u] *= 2ll;
	if (val[u] == 0)
	{
		read(u << 1);
		read(u << 1 | 1);
	}
}

void dfs(int u, int time)
{
	if (dp[u][time] || !time) return;

	if (val[u])
	{
		dp[u][time] = min(val[u], (time - t[u]) / 5);
		return;
	}

	for (int i = 0; i <= time - t[u]; i++)
	{
		dfs(u << 1, i);
		dfs(u << 1 | 1, time - t[u] - i);

		dp[u][time] = max(dp[u][time], dp[u << 1][i] + dp[u << 1 | 1][time - t[u] - i]);
	}
}

void solve()
{
	memset(dp, 0, sizeof(dp));

	cin >> limit;
	limit--;

	read(1);
	dfs(1, limit);

	cout << dp[1][limit];
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	solve();
}