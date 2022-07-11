#include <iostream>

using namespace std;

const int N = 1010, M = 10010;

template<typename T>
class Graph{
private:
	struct edge
	{
		int to, next;
	}e[2 * M];
	int head[N], tot;
	int color[N];
	int size;
	int m[N], vis[N];

public:
	void init(int n)
	{
		size = n;
		tot = 0;
		for (int i = 1; i <= n; i++) head[i] = color[i] = 0;
	}

	void add_edge(int from, int to)
	{
		e[++tot] = {to, head[from]}; head[from] = tot;
		e[++tot] = {from, head[to]}; head[to] = tot;
	}

	bool bio_graph(int u, int type)
	{
		color[u] = type;
		for (int i = head[u]; i; i = e[i].next)
		{
			int v = e[i].to;
			if (!color[v])
			{
				if (!bio_graph(v, 3 - type)) return false;
			}
			else if (color[v] == type) return false;
		}
		return true;
	}

	bool find(int u)
	{
		vis[u] = true;
		for (int i = head[u]; i; i = e[i].next)
		{
			int v = e[i].to;
			if (!m[v] || (!vis[m[v]] && find(m[v])))
			{
				m[v] = u;
				return true;
			}
		}
		return false;
	}

	int match()
	{
		T res = 0;

		for (int i = 1; i <= size; i++) m[i] = 0;
		for (int i = 1; i <= size; i++)
		{
			if (color[i] == 1)
			{
				for (int j = 1; j <= size; j++) vis[j] = false;
				if (find(i)) res++;
			}
		}

		return res;
	}
};

Graph<int> g;
int main()
{
	int n, m;
	cin >> n >> m;
	g.init(n);

	for (int i = 1; i <= m; i++)
	{
		int a, b;
		cin >> a >> b;
		g.add_edge(a, b);
	}

	g.bio_graph(1, 1);

	cout << n - g.match();
}