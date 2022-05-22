#include <iostream>
#include <queue>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;

const int N = 200010;

struct edge
{
	int to, next;
	int val;
}e[2 * N];
int head[N], tot = 0;

void add_edge(int from, int to, int val)
{
	e[++tot].to = to;
	e[tot].val = val;
	e[tot].next = head[from];
	head[from] = tot;
}

int depth[N];
int p[N][17][2];
void bfs(int root)
{
	memset(depth, 0x3f, sizeof(depth));
	depth[0] = 0; depth[root] = 1;

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

				p[j][0][0] = u;
				p[j][0][1] = e[i].val;

				for (int k = 1; k <= 16; k++)
				{
					p[j][k][0] = p[p[j][k - 1][0]][k - 1][0];
					p[j][k][1] = min(p[j][k - 1][1], p[p[j][k - 1][0]][k - 1][1]);
				}
			}
		}
	}
}

int query(int a, int b)
{
	if (depth[a] < depth[b]) return query(b, a);

	int res = p[a][0][1];
	for (int k = 16; k >= 0; k--)
	{
		if (depth[p[a][k][0]] >= depth[b])
		{
			res = min(res, p[a][k][1]);
			a = p[a][k][0];
		}
	}

	if (a == b) return res;

	for (int k = 16; k >= 0; k--)
	{
		if (p[a][k][0] != p[b][k][0])
		{
			res = min({res, p[a][k][1], p[b][k][1]});
			a = p[a][k][0], b = p[b][k][0];
		}
	}

	return min({res, p[a][0][1], p[b][0][1]});
}

void solve()
{
	int n, q;
	cin >> n >> q;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j <= 16; j++)
		{
			p[i][j][1] = 0x3f3f3f3f;
		}
	}

	for (int i = 1; i < n; i++)
	{
		int a, b, v;
		cin >> a >> b >> v;

		add_edge(a, b, v);
		add_edge(b, a, v);
	}

	bfs(1);

	for (int i = 1; i <= q; i++)
	{
		int a, b;
		cin >> a >> b;

		cout << query(a, b) << '\n';
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	solve();
}