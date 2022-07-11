#include <iostream>
#include <algorithm>
#include <queue>
#include <limits>

using namespace std;

const int N = 10100;
const int E = 11000;
template<typename T>
class FlowGraph {
private:
	int s, t, v_cnt;
	struct edge
	{
		int from, to, next;
		T f;
		bool st;
	}e[E * 2];
	int head[N], tot = 0;
	int cur[N], dis[N];
	int size;
	int nx[N];
	bool is_st[N];

	int inv_edge(int x)
	{
		if (x % 2 == 1) return x + 1;
		else return x - 1;
	}

	bool bfs()
	{
		for (int i = 1; i <= v_cnt; i++)
		{
			dis[i] = 0;
			cur[i] = head[i];
		}

		queue<int> q;
		q.push(s); dis[s] = 1;

		while (!q.empty())
		{
			int u = q.front(); q.pop();
			for (int i = head[u]; i; i = e[i].next)
			{
				if (!e[i].f || dis[e[i].to]) continue;
				int v = e[i].to;
				dis[v] = dis[u] + 1;
				if (v == t) return true;
				q.push(v);
			}
		}

		return false;
	}

	T dfs(int u, T m)
	{
		if (u == t) return m;
		T flow = 0;
		for (int i = cur[u]; i; cur[u] = i = e[i].next)
		{
			if (!e[i].f || dis[e[i].to] != dis[u] + 1) continue;
			T f = dfs(e[i].to, min(m, e[i].f));
			e[i].f -= f;
			e[inv_edge(i)].f += f;
			m -= f;
			flow += f;
			if (!m) break;
		}
		if (!flow) dis[u] = -1;
		return flow;
	}

public:
	void add_edge(int from, int to, T val)
	{
		e[++tot] = {from, to, head[from], val, 1}; head[from] = tot;
		if (from == s || to == t) e[tot].st = 0;
		e[++tot] = {to, from, head[to], 0, 0}; head[to] = tot;
	}

	void init(int s_, int t_, int v_cnt_, int sz_)
	{
		s = s_;
		t = t_;
		size = sz_;
		v_cnt = v_cnt_;
		tot = 0;
		for (int i = 1; i <= v_cnt + 2; i++) head[i] = 0;
	}

	void out_put()
	{
		for (int i = 1; i <= tot; i++)
		{
			if (e[i].st == true && e[i].f == 0)
			{
				nx[e[i].from] = e[i].to - size;
				is_st[e[i].to - size] = true;
			}
		}

		for (int i = 1; i <= size; i++)
		{
			if (is_st[i]) continue;
			int k = i;
			while (k)
			{
				cout << k << ' ';
				k = nx[k];
			}
			cout << '\n';
		}
	}

	T dinic()
	{
		T flow = 0;
		while (bfs()) flow += dfs(s, numeric_limits<T>::max());
		return flow;
	}
};

FlowGraph<long long> g;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int n, m;
	cin >> n >> m;

	int s = 2 * n + 1, t = 2 * n + 2;
	g.init(s, t, t, n);

	for (int i = 1; i <= m; i++)
	{
		int a, b;
		cin >> a >> b;
		g.add_edge(a, b + n, 1);
	}

	for (int i = 1; i <= n; i++)
	{
		g.add_edge(s, i, 1);
		g.add_edge(i + n, t, 1);
	}

	long long res = n - g.dinic();
	g.out_put();
	cout << res;
}