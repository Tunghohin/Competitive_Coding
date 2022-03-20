#include <iostream>

using namespace std;

const int N = 510;

int n, m;
int val[N];
long long dp[N][N][2];

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
	for (int i = head[u]; i; i = e[i].next)
	{
		int t = e[i].to;

		dfs(t);
		for (int j = m; j >= 0; j--)
		{
			for (int k = 0; k <= j; k++)
			{
				dp[u][j][0] = max(dp[u][j][0], dp[u][j - k][0] + max(dp[t][k][0], dp[t][k][1]));
				dp[u][j][1] = max(dp[u][j][1], dp[u][j - k][1] + dp[t][k][0]);
			}
		}
	}
	for (int j = m; j >= 1; j--) dp[u][j][1] = dp[u][j - 1][1] + val[u];
	dp[u][0][1] = dp[u][0][0] = 0;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	cin >> n >> m;

	for (int i = 2; i <= n; i++)
	{
		int x;
		cin >> x;
		add_edge(x, i);
	}

	for (int i = 1; i <= n; i++) cin >> val[i];

	dfs(1);

	cout << max(dp[1][m][0], dp[1][m][1]);
}