#include <iostream>
#include <cstring>

using namespace std;

const int N = 50;

template<typename T>
class Graph{
private:
	int size;
	struct edge
	{
		int to, next;
		int val;
	}e[4 * N * N];
	int head[N * N], tot;
	int m[N * N];
	bool st[N * N];

public:
	bool vis[N * N];

	void init(int n)
	{
		size = n;
		memset(vis, 0, sizeof(vis));
		memset(head, 0, sizeof(head));
		tot = 0;
	}

	void add_edge(int from, int to, int val)
	{
		e[++tot] = {to, head[from], val}; head[from] = tot;
		e[++tot] = {from, head[to], val}; head[to] = tot;
	}

	bool find(int u)
	{
		st[u] = true;
		for (int i = head[u]; i; i = e[i].next)
		{
			int v = e[i].to;
			if (!m[v] || (!st[m[v]] && find(m[v])))
			{
				m[v] = u;
				return true;
			}
		}
		return false;
	}

	int match()
	{
		int res = 0;
		memset(m, 0, sizeof(m));
		for (int i = 1; i <= size; i++)
		{
			for (int j = 1 + (i % 2 == 0); j <= size; j += 2)
			{
				memset(st, 0, sizeof(st));
				if (find(size * (i - 1) + j)) res++;
			}
		}
		return res;
	}
};

Graph<int> g;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int n, m;
	cin >> n >> m;

	g.init(n);

	for (int i = 1; i <= m; i++)
	{
		int a, b;
		cin >> a >> b;
		g.vis[n * (a - 1) + b] = true;
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (g.vis[n * (i - 1) + j]) continue;
			if (j < n && !g.vis[n * (i - 1) + j + 1]) g.add_edge(n * (i - 1) + j, n * (i - 1) + j + 1, 1);
			if (i < n && !g.vis[n * i + j]) g.add_edge(n * (i - 1) + j, n * i + j, 1);
		}
	}

	cout << g.match() * 2;
}