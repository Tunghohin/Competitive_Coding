#include <iostream>

using namespace std;

const int N = 100010;

int dp[N];
pair<int, int> mx_down[N], smx_down[N], mx[N], smx[N];

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
	for (int i = head[u]; i; i = e[i].next)
	{
		int j = e[i].to;
		if (j == from) continue;

		dfs_1(j, u);
		if (mx_down[j].first + 1 > mx_down[u].first)
		{
			smx_down[u] = mx_down[u];
			mx_down[u].first = mx_down[j].first + 1;
			mx_down[u].second = j;
		}
		else if (mx_down[j].first + 1 > smx_down[u].first)
		{
			smx_down[u].first = mx_down[j].first + 1;
			smx_down[u].second = j;
		}
	}
}

void dfs_2(int u, int from)
{
	if (u == 1)
	{
		mx[u] = mx_down[u];
		smx[u] = smx_down[u];
	}
	else
	{
		int mx_up = mx[from].first + 1;
		if (mx[from].second == u)
		{
			mx_up = smx[from].first + 1;
		}

		if (mx_up >= mx_down[u].first)
		{
			mx[u].first = mx_up;
			mx[u].second = from;
			smx[u] = mx_down[u];
		}
		else if (mx_up >= smx_down[u].first)
		{
			mx[u] = mx_down[u];
			smx[u].first = mx_up;
			smx[u].second = from;
		}
		else
		{
			mx[u] = mx_down[u];
			smx[u] = smx_down[u];
		}
	}

	dp[u] = mx[u].first + smx[u].first;

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

	int n;
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