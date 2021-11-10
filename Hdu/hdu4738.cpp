#include <cstring>
#include <iostream>

using namespace std;

const int N = 1010, M = 200;

struct edge
{
	int to, next, val;
}e[M];
int head[N], tot = 0;

void add_edge(int from, int to, int val)
{
	e[++tot].to = to;
	e[tot].val = val;
	e[tot].next = head[from];
	head[from] = tot;
}

int inv_edge(int i)
{
	return i - ((i ^ 1) - i);
}

int dfn[N], low[N], timestamp = 0;
bool is_bridge[M];
void tarjan(int u, int from)
{
	dfn[u] = low[u] = ++timestamp;

	for (int i = head[u]; i; i = e[i].next)
	{
		int j = e[i].to;

		if (!dfn[j])
		{
			tarjan(j, i);
			low[u] = min(low[u], low[j]);

			if (dfn[u] < low[j]) is_bridge[i] = is_bridge[inv_edge(i)] = true;
		}

		else if (i != (inv_edge(from))) low[u] = min(low[u], dfn[j]);
	}
}

void init(int n)
{
	for (int i = 0; i <= n; i++)
	{
		dfn[i] = low[i] = 0;
		head[i] = 0;
	}

	timestamp = tot = 0;
	memset(is_bridge, false, sizeof(is_bridge));
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int n, m;
	while (cin >> n >> m, n || m)
	{
		init(n);

		for (int i = 1; i <= m; i++)
		{
			int a, b, v;
			cin >> a >> b >> v;
			add_edge(a, b, v), add_edge(b, a, v);
		}

		int cnt = 0;
		for (int i = 1; i <= n; i++)
		{
			if (!dfn[i]) tarjan(i, -1), cnt++;
		}

		if (cnt > 1)
		{
			cout << 0 << '\n';
			continue;
		}

		int res = 0x3f3f3f3f;
		for (int i = 1; i <= tot; i += 2)
		{
			if (is_bridge[i])
			{
				res = min(res, e[i].val);
			}
		}

		if (res == 0x3f3f3f3f) cout << -1 << '\n';
		else if (res == 0) cout << 1 << '\n';
		else cout << res << '\n';
	}
}