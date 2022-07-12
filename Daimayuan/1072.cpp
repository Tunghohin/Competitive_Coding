#include <iostream>
#include <cstring>
#include <limits>
#include <queue>

using namespace std;

const long long inf = 0x3f3f3f3f;
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
};

FlowGraph<long long> g;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int m, n;
	cin >> m >> n;

	int s = n * m + 1, t = s + 1;
	g.init(s, t, t, n * m);

	int sum = 0;
	for (int i = 1; i <= m; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			int id = n * (i - 1) + j;
			int x;
			cin >> x;
			sum += x;
			if ((i + j) % 2)
			{
				g.add_edge(s, id, x);
				if (i - 1 >= 1) g.add_edge(id, id - n, inf);
				if (i + 1 <= m) g.add_edge(id, id + n, inf);
				if (j - 1 >= 1) g.add_edge(id, id - 1, inf);
				if (j + 1 <= n) g.add_edge(id, id + 1, inf);
			} else g.add_edge(id, t, x);
		}
	}

	cout << sum - g.dinic();
}
