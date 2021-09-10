#include <iostream>

using namespace std;

struct edge
{
	int to, next;
}e[20010];
int head[10010], tot = 0;

void add_edge(int from, int to)
{
	e[++tot].to = to;
	e[tot].next = head[from];
	head[from] = tot;
}

int res[10010], size[10010], sum[10010];
void dfs(int u, int last)
{
	size[u] = 1;

	for (int i = head[u]; i; i = e[i].next)
	{
		int j = e[i].to;

		if (j == last) continue;

		dfs(j, u);
		size[u] += size[j];
		sum[u] += size[j] * size[j];
	}

	res[u] = size[u] * size[u] - sum[u];
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int n, root, m;
	cin >> n >> root >> m;

	for (int i = 1; i < n; i++)
	{
		int a, b;
		cin >> a >> b;
		add_edge(a, b), add_edge(b, a);
	}

	dfs(root, 0);

	for (int i = 1; i <= m; i++)
	{
		int q;
		cin >> q;
		cout << res[q] << '\n';
	}
}