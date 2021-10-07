#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

int type[200010];

struct edge
{
	int to, next;
}e[400010];
int head[200010], tot;

void add_edge(int from, int to)
{
	e[++tot].to = to;
	e[tot].next = head[from];
	head[from] = tot;
}

void dfs(int u, int last)
{
	bool leaves = false;
	for (int i = head[u]; i; i = e[i].next)
	{
		int j = e[i].to;
		if (j == last) continue;

		dfs(j, u);
		if (type[j] == 1) leaves = true;
	}

	if (u != last)
	{
		if (leaves) type[u] = 2;
		else type[u] = 1;
	}
}

void solve()
{
	memset(type, -1, sizeof(type));
	memset(head, 0, sizeof(head));
	tot = 0;

	int n;

	cin >> n;

	for (int i = 1; i < n; i++)
	{
		int x, y;
		cin >> x >> y;

		add_edge(x, y);
		add_edge(y, x);
	}

	type[1] = 0;
	dfs(1, 1);

	bool root_leaf = false;

	for (int i = head[1]; i; i = e[i].next)
	{
		int j = e[i].to;

		if (type[j] == 1)
		{
			root_leaf = true;
			break;
		}
	}

	int k = 0;

	for (int i = 1; i <= n; i++)
	{
		k += (type[i] == 2);
	}

	cout << n - 2 * k - root_leaf << '\n';
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int T;
	cin >> T;

	for (int i = 1; i <= T; i++)
	{
		solve();
	}
}