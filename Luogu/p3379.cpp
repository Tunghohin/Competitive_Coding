#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

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

int depth[500010];
int p[500010][20];
void bfs(int root)
{
	memset(depth, 0x3f, sizeof(depth));
	depth[0] = 0, depth[root] = 1;

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

				p[j][0] = u;
				for (int k = 1; k <= 15; k++) p[j][k] = p[p[j][k - 1]][k - 1];
			}
		}
	}
}

int lca(int a, int b)
{
	if (depth[a] < depth[b]) return lca(b, a);

	for (int k = 15; k >= 0; k--)
	{
		if (depth[p[a][k]] >= depth[b]) a = p[a][k];
	}

	if (a == b) return b;

	for (int k = 15; k >= 0; k--)
	{
		if (p[a][k] != p[b][k]) a = p[a][k], b = p[b][k];
	}

	return p[a][0];
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int n, q, root;
	cin >> n >> q >> root;

	for (int i = 1; i < n; i++)
	{
		int a, b;
		cin >> a >> b;
		add_edge(a, b), add_edge(b, a);
	}

	bfs(root);

	while (q--)
	{
		int a, b;
		cin >> a >> b;

		cout << lca(a, b) << '\n';
	}
}