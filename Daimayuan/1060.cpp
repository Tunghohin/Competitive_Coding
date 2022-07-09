#include <iostream>
#include <limits>
#include <queue>
#include <numeric>

using namespace std;

int nn, mm;

const int N = 100100;
const int E = 101000;
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

	void init(int s_, int t_, int v_cnt_)
	{
		s = s_;
		t = t_;
		v_cnt = v_cnt_;
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

vector<pair<int, int>> games(10010);
FlowGraph<long long> g;
bool check(int x)
{
	int s = nn + mm + 1;
	int t = nn + mm + 2;
	g.init(s, t, t);
	for (int i = 1; i <= mm; i++)
	{
		g.add_edge(s, i, 1);
		g.add_edge(i, games[i].first + mm, 1);
		g.add_edge(i, games[i].second + mm, 1);
	}
	for (int i = 1; i <= nn; i++)
	{
		g.add_edge(i + mm, t, x);
	}

	long long res = g.dinic();
	return res == mm;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	cin >> nn >> mm;

	for (int i = 1; i <= mm; i++)
	{
		int a, b;
		cin >> a >> b;
		games[i] = {a, b};
	}

	int l = 1, r = mm;
	while (l < r)
	{
		int mid = (l + r) >> 1;
		if (check(mid)) r = mid;
		else l = mid + 1;
	}

	cout << l;
}