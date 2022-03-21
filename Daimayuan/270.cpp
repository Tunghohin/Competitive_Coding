#include <iostream>

using namespace std;

const int N = 50010;

int size[N];
int val[N];
long long dp[N][110];

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

void dfs(int u)
{
	size[u] = 0;
	static long long tmp[100];
	for (int i = head[u]; i; i = e[i].next)
	{
		int to = e[i].to;
		dfs(to);
		for (int j = 0; j <= 200; j++) tmp[j] = -0x3f3f3f3f;

		for (int j = 0; j <= 100 && j <= size[u]; j++)
		{
			for (int k = 0; j + k <= 100 && k <= size[to]; k++)
			{
				tmp[j + k] = max(tmp[j + k], dp[u][j] + dp[to][k]);
			}
		}

		for (int j = 0; j <= 100; j++) dp[u][j] = tmp[j];
		size[u] += size[to];
	}

	size[u] += 1;
	for (int i = 100; i >= 1; i--) dp[u][i] = dp[u][i - 1] + val[u];
	dp[u][0] = 0;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int n, q;
	cin >> n >> q;

	for (int i = 2; i <= n; i++)
	{
		int x;
		cin >> x;
		add_edge(x, i);
	}

	for (int i = 1; i <= n; i++) cin >> val[i];

	dfs(1);

	for (int i = 1; i <= q; i++)
	{
		int qx, qm;
		cin >> qx >> qm;
		cout << dp[qx][qm] << '\n';
	}
}