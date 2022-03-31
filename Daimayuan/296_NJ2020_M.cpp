#include <iostream>

using namespace std;

const int N = 2010;

int hp[N];
long long dp[N][N][2];
int size[N];

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

void init(int n)
{
	tot = 0;
	for (int i = 0; i <= n; i++)
	{
		head[i] = 0;
	}
	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j <= n; j++) dp[i][j][0] = dp[i][j][1] = 0;
	}
}

void dfs(int u)
{
	size[u] = 1;
	static long long tmp[N][2];

	dp[u][0][0] = hp[u];
	dp[u][1][0] = 0x3f3f3f3f3f3f3f3f;
	dp[u][0][1] = 0x3f3f3f3f3f3f3f3f;
	dp[u][1][1] = 0;

	for (int i = head[u]; i; i = e[i].next)
	{
		int to = e[i].to;
		dfs(to);

		for (int j = 0; j <= size[u] + size[to]; j++)
		{
			tmp[j][0] = tmp[j][1] = 0x3f3f3f3f3f3f3f3f;
		}

		for (int j = 0; j <= size[u]; j++)
		{
			for (int k = 0; k <= size[to]; k++)
			{
				tmp[j + k][0] = min(tmp[j + k][0], dp[u][j][0] + dp[to][k][0] + hp[to]);
				tmp[j + k][0] = min(tmp[j + k][0], dp[u][j][0] + dp[to][k][1]);
				tmp[j + k][1] = min(tmp[j + k][1], dp[u][j][1] + min(dp[to][k][0], dp[to][k][1]));
			}
		}

		for (int j = 0; j <= size[u] + size[to]; j++)
		{
			dp[u][j][0] = tmp[j][0];
			dp[u][j][1] = tmp[j][1];
		}

		size[u] += size[to];
	}
}

void solve()
{
	int n;
	cin >> n;

	init(n);

	for (int i = 2; i <= n; i++)
	{
		int x;
		cin >> x;
		add_edge(x, i);
	}

	for (int i = 1; i <= n; i++) cin >> hp[i];

	dfs(1);

	for (int i = 0; i <= n; i++)
	{
		cout << min(dp[1][i][0], dp[1][i][1]) << ' ';
	}
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
		if (T) cout << '\n';
	}
}