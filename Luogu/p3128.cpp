#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int d[50010];

struct edge
{
	int to, next;
}e[100010];
int head[50010], tot = 0;

void add_edge(int from, int to)
{
	e[++tot].to = to;
	e[tot].next = head[from];
	head[from] = tot;
}

int depth[50010];
int f[50010][20];
void bfs(int root)
{
	queue<int> q;
	memset(depth, 0x3f, sizeof(depth));

	depth[0] = 0, depth[root] = 1;

	q.push(root);

	while (!q.empty())
	{
		int u = q.front();
		q.pop();

		for (int i = head[u]; i; i = e[i].next)
		{
			int j = e[i].to;

			if (depth[j] > depth[u] + 1)
			{
				depth[j] = depth[u] + 1;
				q.push(j);

				f[j][0] = u;
				for (int k = 1; k <= 15; k++) f[j][k] = f[f[j][k - 1]][k - 1];
			}
		}
	}
}

int lca(int a, int b)
{
	if (depth[a] < depth[b]) return lca(b, a);

	for (int k = 15; k >= 0; k--)
	{
		if (depth[f[a][k]] >= depth[b]) a = f[a][k];
	}

	if (a == b) return b;

	for (int k = 15; k >= 0; k--)
	{
		if (f[a][k] != f[b][k]) a = f[a][k], b = f[b][k];
	}

	return f[b][0];
}

int maxn = -0x3f3f3f3f;
int dfs(int u, int last)
{
	int now = d[u];

	for (int i = head[u]; i; i = e[i].next)
	{
		int j = e[i].to;
		if (j == last) continue;

		now += dfs(j, u);
	}

	maxn = max(maxn, now);
	return now;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int n, k;
	cin >> n >> k;

	for (int i = 1; i < n; i++)
	{
		int a, b;
		cin >> a >> b;
		add_edge(a, b), add_edge(b, a);
	}

	bfs(1);

	while (k--)
	{
		int a, b;
		cin >> a >> b;

		int p = lca(a, b);
		d[a]++, d[b]++;
		d[p]--;
		d[f[p][0]]--;
	}

	dfs(1, 0);

	cout << maxn << '\n';
}