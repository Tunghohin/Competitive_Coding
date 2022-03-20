#include <iostream>

using namespace std;

const int N = 100010;

long long val[N], dp[N][2];

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
	dp[u][0] = 0, dp[u][1] = val[u];
	for (int i = head[u]; i; i = e[i].next)
	{
		int j = e[i].to;
		dfs(j);
		dp[u][0] += max(dp[j][0], dp[j][1]);
		dp[u][1] += dp[j][0];
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int n;
	cin >> n;

	for (int i = 2; i <= n; i++)
	{
		int x;
		cin >> x;
		add_edge(x, i);
	}

	for (int i = 1; i <= n; i++) cin >> val[i];

	dfs(1);

	cout << max(dp[1][0], dp[1][1]);
}