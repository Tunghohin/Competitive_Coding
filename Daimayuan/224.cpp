#include <iostream>
#pragma GCC optimize(2)

using namespace std;

const int N = 100010;
int n;

long long sum[N], size[N], dp[N];

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

void dfs_1(int u, int from)
{
	size[u] = 1;
	for (int i = head[u]; i; i = e[i].next)
	{
		int j = e[i].to;
		if (j == from) continue;
		dfs_1(j, u);
		size[u] += size[j];
		sum[u] += sum[j] + size[j];
	}
}

void dfs_2(int u, int from)
{
	if (u == 1) dp[u] = sum[u];
	else dp[u] = dp[from] - size[u] + n - size[u];

	for (int i = head[u]; i; i = e[i].next)
	{
		int j = e[i].to;
		if (j == from) continue;

		dfs_2(j, u);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	cin >> n;

	for (int i = 1; i < n; i++)
	{
		int a, b;
		cin >> a >> b;
		add_edge(a, b), add_edge(b, a);
	}

	dfs_1(1, 0);
	dfs_2(1, 0);

	for (int i = 1; i <= n; i++) cout << dp[i] << '\n';
}