#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

struct edge
{
	int to, next;
}e[200010];
int head[100010], tot = 0;

void add_edge(int from, int to)
{
	e[++tot].to = to;
	e[tot].next = head[from];
	head[from] = tot;
}

char cow[100010];
char is_satisfy[100010];

int depth[100010];
int prefix[100010];
int f[100010][20];
void bfs(int root)
{
	queue<int> q;
	memset(depth, 0x3f, sizeof(depth));

	depth[0] = 0; depth[root] = 1;

	cow[root] == 'H'? prefix[root] = 1 : prefix[root] = 0;

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

				cow[j] == 'H'? prefix[j] = prefix[u] + 1 : prefix[j] = prefix[u];
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

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= n; i++) cin >> cow[i];

	for (int i = 1; i < n; i++)
	{
		int fr, to;
		cin >> fr >> to;
		add_edge(fr, to);
		add_edge(to, fr);
	}

	bfs(1);

	for (int i = 1; i <= m; i++)
	{
		int fr, to;
		char op[2];

		cin >> fr >> to >> op;

		int p = lca(fr, to);

		if (op[0] == 'H')
		{
			int res = prefix[fr] + prefix[to] - prefix[p] - prefix[f[p][0]];
			res == 0 ? is_satisfy[i] = '0' : is_satisfy[i] = '1';
		}
		else
		{
			int length = depth[fr] + depth[to] - depth[p] - depth[f[p][0]];
			int res = prefix[fr] + prefix[to] - prefix[p] - prefix[f[p][0]];

			res < length ? is_satisfy[i] = '1' : is_satisfy[i] = '0';
		}
	}

	for (int i = 1; i <= m; i++) cout << is_satisfy[i];
}