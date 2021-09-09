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
int f[500010][20];
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

int size[500010];
int dfs(int u)
{
	size[u] = 0;

	for (int i = head[u]; i; i = e[i].next)
	{
		int j = e[i].to;
		size[u] += dfs(j);
	}

	return size[u];
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int n, q;
	cin >> n >> q;

	for (int i = 1; i < n; i++)
	{
		int fr, to;
		cin >> fr >> to;
		add_edge(fr, to), add_edge(to, fr);
	}

	bfs(1);
	dfs(1);
}