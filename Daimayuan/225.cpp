#include <iostream>
#define int long long

//注意成链的corner case

using namespace std;

const int N = 100010;

long long max_flow[N];
long long max_up[N];
long long dp[N];

struct edge
{
	int to, next;
	long long cap;
}e[2 * N];
int head[N], tot = 0;

void add_edge(int from, int to, int cap)
{
	e[++tot].cap = cap;
	e[tot].to = to;
	e[tot].next = head[from];
	head[from] = tot;
}

int inv_edge(int x)
{
	return x & 1? x + 1 : x - 1;
}

void dfs_1(int u, int from)
{
	long long son_sum = 0;
	for (int i = head[u]; i; i = e[i].next)
	{
		if (i == inv_edge(from)) continue;
		int j = e[i].to;
		dfs_1(j, i);

		son_sum += max_flow[j];
	}
	if (son_sum == 0) max_flow[u] = e[from].cap;
	else if (e[from].cap == 0) max_flow[u] = son_sum;
	else max_flow[u] = min(e[from].cap, son_sum);
}

void dfs_2(int u, int from)
{
	long long son_sum = 0;
	for (int i = head[u]; i; i = e[i].next)
	{
		if (i == inv_edge(from)) continue;
		int j = e[i].to;
		son_sum += max_flow[j];
	}

	if (u == 1) dp[u] = son_sum;
	else
	{
		if (e[inv_edge(from)].to == 1) max_up[u] = e[from].cap;
		else
		{
			max_up[u] = min(e[from].cap, dp[e[inv_edge(from)].to] - max_flow[u]);
		}
		dp[u] = son_sum + max_up[u];
	}

	for (int i = head[u]; i; i = e[i].next)
	{
		if (i == inv_edge(from)) continue;
		int j = e[i].to;

		dfs_2(j, i);
	}
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) max_flow[i] = 0x3f3f3f3f;

	for (int i = 1; i < n; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		add_edge(a, b, c), add_edge(b, a, c);
	}

	dfs_1(1, 0);
	dfs_2(1, 0);

	for (int i = 1; i <= n; i++) cout << dp[i] << '\n';
}