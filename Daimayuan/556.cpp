#include <iostream>

using namespace std;

struct edge
{
	int to, next;
}e[1000010];
int head[500010], tot = 0;

void add_edge(int from, int to)
{
	e[++tot].to = to;
	e[tot].next = head[from];
	head[from] = tot;
}

int res = -1;
int dp[500010][2];
int val[500010];
void dfs(int u, int from)
{
	dp[u][0] = dp[u][1] = 1;
	for (int i = head[u]; i; i = e[i].next)
	{
		int j = e[i].to;
		if (j == from) continue;
		dfs(j, u);

		if (val[u] == (val[j] + 1) % 3) //0
		{
			dp[u][0] = max(dp[u][0], dp[j][0] + 1);
		}
		else if (val[j] == (val[u] + 1) % 3)
		{
			dp[u][1] = max(dp[u][1], dp[j][1] + 1);
		}
	}
	res = max(res, dp[u][0] + dp[u][1] - 1);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int n;
	cin >> n;

	for (int i = 1; i < n; i++)
	{
		int f, t;
		cin >> f >> t;

		add_edge(f, t), add_edge(t, f);
	}

	for (int i = 1; i <= n; i++) cin >> val[i];

	dfs(1, 0);

	cout << res;
}