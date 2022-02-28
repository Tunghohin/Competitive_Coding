#include <iostream>
#include <cmath>
#include <queue>
#include <cstring>

using namespace std;

struct edge
{
	int to, next;
}e[400010];
int head[200010], tot = 0;

void add_edge(int from, int to)
{
	e[++tot].to = to;
	e[tot].next = head[from];
	head[from] = tot;
}

int val[200010];
int xor_prefix[200010];

int depth[200010];
int f[200010][31];
void bfs(int root)
{
	memset(depth, 0x3f, sizeof(depth));
	depth[0] = 0, depth[root] = 1;

	xor_prefix[root] = val[root];

	queue<int> q;
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
				for (int k = 1; k < 20; k++)
				{
					f[j][k] = f[f[j][k - 1]][k - 1];
				}

				xor_prefix[j] = xor_prefix[u] ^ val[j];
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

	for (int k = 20; k >= 0; k--)
	{
		if (f[a][k] != f[b][k]) a = f[a][k], b = f[b][k];
	}

	return f[b][0];
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= n; i++) cin >> val[i];

	for (int i = 1; i < n; i++)
	{
		int from, to;
		cin >> from >> to;

		add_edge(from, to);
		add_edge(to, from);
	}

	bfs(1);

	while (m--)
	{
		int a, b;
		cin >> a >> b;

		int Lca = lca(a, b);

		cout << (xor_prefix[a] ^ xor_prefix[b] ^ val[Lca]) << '\n';
	}
}
