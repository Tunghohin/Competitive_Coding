#include <iostream>
#include <queue>

using namespace std;

int depth[500010];
int f[500010][25];
int size[500010];

struct edge
{
	int to, next;
}e[1000010];
int head[500010], tot = 0;

void add_edge(int from, int to)
{
	e[++tot].to = to;
	e[tot].next = head[from];
	head[from] = tot;
}

void dfs(int u, int last)
{
	depth[u] = depth[last] + 1;
	size[u] = 1;

	f[u][0] = last;
	for (int i = 1; i <= 15; i++) f[u][i] = f[f[u][i - 1]][i - 1];

	for (int i = head[u]; i; i = e[i].next)
	{
		int j = e[i].to;

		if (j == last) continue;

		dfs(j, u);
		size[u] += size[j];
	}
}

int lca(int a, int b)
{
	if (a == b) return b;
	if (depth[a] < depth[b]) swap(a, b);

	for (int k = 15; k >= 0; k--)
	{
		if (depth[f[a][k]] >= depth[b]) a = f[a][k];
		if (a == b) return b;
	}

	for (int k = 15; k >= 0; k--)
	{
		if (f[a][k] != f[b][k]) a = f[a][k], b = f[b][k];
	}

	return f[b][0];
}

int get(int a, int b)
{
	if (a == b) return 0;

	for (int k = 15; k >= 0; k--)
	{
		if (depth[f[a][k]] > depth[b]) a = f[a][k];
	}

	return size[a];
}

int get_dist(int a, int b)
{
	return depth[a] + depth[b] - (2 * depth[lca(a, b)]);
}

int main()
{
	int n, q;
	scanf("%d%d", &n, &q);

	for (int i = 1; i <= n - 1; i++)
	{
		int fr, to;
		scanf("%d%d", &fr, &to);
		add_edge(fr, to), add_edge(to, fr);
	}

	dfs(1, 0);

	for (int i = 1; i <= q; i++)
	{
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);

		int p = lca(a, b);

		if (c == p)
		{
			int res =  n - get(a, c) - get(b, c);
			printf("%d\n", res);
			continue;
		}

		if (get_dist(a, c) + get_dist(c, p) == get_dist(a, p))
		{
			int res = size[c] - get(a, c);
			printf("%d\n", res);
			continue;
		}

		if (get_dist(b, c) + get_dist(c, p) == get_dist(b, p))
		{
			int res = size[c] - get(b, c);
			printf("%d\n", res);
			continue;
		}

		printf("0\n");
	}
}