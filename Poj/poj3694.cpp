#include <iostream>
#include <cstring>
#define nullptr 0

using namespace std;

const int N = 100010, M = 400010;

struct edge
{
	int to, next;
}e[M];
int head[N], tot = 0;

void add_edge(int from, int to)
{
	e[++tot].to = to;
	e[tot].next = head[from];
	head[from] = tot;
}

int inv_edge(int i)
{
	return i - ((i ^ 1) - i);
}

int dfn[N], low[N], timestamp;
int f[N], depth[N];
bool in_bridge[N];
int cnt;
void tarjan(int u, int from)
{
	dfn[u] = low[u] = ++timestamp;

	for (int i = head[u]; i; i = e[i].next)
	{
		int j = e[i].to;

		if (!dfn[j])
		{
			depth[j] = depth[u] + 1;
			f[j] = u;
			tarjan(j, i);
			low[u] = min(low[u], low[j]);

			if (dfn[u] < low[j]) in_bridge[j] = true, cnt++;
		}

		else if (i != inv_edge(from)) low[u] = min(low[u], dfn[j]);
	}
}

void lca(int a, int b)
{
	while (depth[a] > depth[b])
	{
		if (in_bridge[a]) cnt--, in_bridge[a] = false;
		a = f[a];
	}

	while (depth[b] > depth[a])
	{
		if (in_bridge[b]) cnt--, in_bridge[b] = false;
		b = f[b];
	}

	while (a != b)
	{
		if (in_bridge[a]) cnt--, in_bridge[a] = false;
		if (in_bridge[b]) cnt--, in_bridge[b] = false;
		a = f[a], b = f[b];
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int T = 0;
	int n, m;
	while (cin >> n >> m, n || m)
	{
		memset(head, 0, sizeof(head));
		memset(dfn, 0, sizeof(dfn));
		memset(low, 0, sizeof(low));
		memset(in_bridge, false, sizeof(in_bridge));
		memset(f, 0, sizeof(f));
		memset(depth, 0, sizeof(depth));
		timestamp = tot = 0;

		for (int i = 1; i <= m; i++)
		{
			int a, b;
			cin >> a >> b;
			add_edge(a, b), add_edge(b, a);
		}

		tarjan(1, -1);

		int q_cnt;
		cin >> q_cnt;

		cout << "Case " << ++T << ":\n";
		while (q_cnt--)
		{
			int a, b;
			cin >> a >> b;

			lca(a, b);

			cout << cnt << '\n';
		}

		cout << '\n';
	}
}