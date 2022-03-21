#include <iostream>

using namespace std;

const int N = 1010, M = 10010;
int dfn[N], timestamp = 0;
int r[N];
int val[N], cost[N];
long long dp[N][M];

struct edge
{
	int to, next;
}e[N];
int head[N], tot = 0;

void add_edge(int from, int to)
{
	e[++tot].to = to;
	e[tot].next = head[from];
	head[from] = tot;
}

void dfs(int u)
{
	dfn[++timestamp] = u;

	for (int i = head[u]; i; i = e[i].next)
	{
		dfs(e[i].to);
	}

	r[u] = timestamp;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int n, m;
	cin >> n >> m;

	for (int i = 2; i <= n; i++)
	{
		int x;
		cin >> x;
		add_edge(x, i);
	}

	for (int i = 1; i <= n; i++) cin >> val[i];
	for (int i = 1; i <= n; i++) cin >> cost[i];

	dfs(1);

	for (int j = 1; j <= m; j++) dp[n + 1][j] = -0x3f3f3f3f;
	for (int i = n; i >= 1; i--)
	{
		int u = dfn[i];
		for (int j = 0; j <= m; j++)
		{
			dp[i][j] = dp[r[u] + 1][j];
			if (j >= cost[u]) dp[i][j] = max(dp[i][j], dp[i + 1][j - cost[u]] + val[u]);
		}
	}

	for (int i = 0; i <= m; i++)
	{
		if (dp[1][i] >= 0) cout << dp[1][i] << '\n';
		else cout << 0 << '\n';
	}
}