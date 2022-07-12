#include <iostream>
#include <cstring>
#include <limits>
#include <queue>

using namespace std;

const long long inf = 0x3f3f3f3f3f3f3f3f;
const int N = 1010;
const int E = 200010;
template<typename T>
class FlowGraph {
private:
	int s, t, v_cnt;
	struct edge
	{
		int to, next;
		T f;
	}e[E * 2];
	int head[N], tot = 0;
	int cur[N], dis[N];
	int sz;

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
		e[++tot] = {to, head[from], val}; head[from] = tot;
		e[++tot] = {from, head[to], 0}; head[to] = tot;
	}

	void init(int s_, int t_, int v_cnt_, int sz_)
	{
		s = s_;
		t = t_;
		v_cnt = v_cnt_;
		sz = sz_;
		tot = 0;
		for (int i = 1; i <= v_cnt + 2; i++) head[i] = 0;
	}

	T dinic()
	{
		T flow = 0;
		while (bfs()) flow += dfs(s, numeric_limits<T>::max());
		return flow;
	}

	void get_cut()
	{
		vector<int> res;
		for (int i = 1; i <= sz; i++)
		{
			if (dis[i] > 0 && dis[i + sz] == 0)
			{
				res.push_back(i);
			}
		}
		cout << res.size() << '\n';
		for (auto u : res)
		{
			cout << u << ' ';
		}
	}
};

FlowGraph<long long> g;
signed main()
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
		g.add_edge(a + n, b, inf);
		g.add_edge(b + n, a, inf);
	}

	g.add_edge(s, 1, inf);
	g.add_edge(n + n, t, inf);
	for (int i = 1; i <= n; i++)
	{
		long long x;
		cin >> x;
		if (i == 1 || i == n)
		{
			g.add_edge(i, i + n, inf);
		}
		else g.add_edge(i, i + n, x);
	}

	cout << g.dinic() << '\n';
	g.get_cut();
}