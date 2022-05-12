#include <iostream>

using namespace std;

const int N = 200010;

int t[N];

struct edge
{
	int to, next;
}e[2 * N];
int head[N], tot = 0;

void add_edge(int from, int to)
{
	e[++tot].to = to;
	e[tot].next = head[from];
	head[from] = tot;
}

int dp[N][2];
int depth[N];
int x, y;
void dfs(int u, int from)
{
	depth[u] = depth[from] + 1;

	for (int i = head[u]; i; i = e[i].next)
	{
		int j = e[i].to;
		if (j == from) continue;
		dfs(j, u);

		if (dp[j][1])
		{
			dp[u][1] = 1;
			dp[u][0] += dp[j][0] + 2;
		}
	}

	if (t[u] || u == y) dp[u][1] = 1;
}

void solve()
{
	int n, k;
	cin >> n >> k >> x >> y;

	tot = 0;
	for (int i = 0; i <= n; i++)
	{
		dp[i][0] = dp[i][1] = 0;
		head[i] = 0;
		depth[i] = 0;
		t[i] = false;
	}

	for (int i = 1; i <= k; i++)
	{
		int id;
		cin >> id;
		t[id] = true;
	}

	for (int i = 1; i < n; i++)
	{
		int a, b;
		cin >> a >> b;
		add_edge(a, b);
		add_edge(b, a);
	}

	dfs(x, 0);

	cout << dp[x][0] - (depth[y] - depth[x]) << '\n';
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int T;
	cin >> T;

	while (T--)
	{
		solve();
	}
}