#include <iostream>
#include <queue>
#include <numeric>
#include <limits>

using namespace std;

const int N = 10100;
const int E = 100100;

template<typename T>
class FlowGraph {
public:
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

public:
	int get_cap(int i)
	{
		return e[i].f;
	}

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

	int k, n;
	cin >> k >> n;

	int s = k + n + 1;
	int t = k + n + 2;
	//req 1~k prob k+1~k+n

	g.init(s, t, k + n + 2);

	long long m = 0;
	for (int i = 1; i <= k; i++)
	{
		int x;
		cin >> x;
		m += x;
		g.add_edge(s, i, x);
	}

	for (int i = 1; i <= n; i++)
	{
		int cnt;
		cin >> cnt;
		g.add_edge(k + i, t, 1);
		for (int j = 1; j <= cnt; j++)
		{
			int x;
			cin >> x;
			g.add_edge(x, k + i, 1);
		}
	}

	long long res = g.dinic();

	if (res != m)
	{
		cout << "No Solution!\n";
		return 0;
	}

	for (int u = 1; u <= k; u++)
	{
		vector<int> probs;
		for (int i = g.head[u]; i; i = g.e[i].next)
		{
			int v = g.e[i].to;
			if (g.e[i].f == 0)
			{
				probs.push_back(v - k);
			}
		}
		cout << u << ':';
		if (probs.empty()) cout << ' ';
		else for (auto i : probs) cout << ' ' << i;
		cout << '\n';
	}
}