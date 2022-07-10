#include <iostream>
#include <limits>
#include <queue>

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

FlowGraph<long long> g1;
FlowGraph<long long> g2;
int a[N], dp[N];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) cin >> a[i];

	int maxn = 0;
	for (int i = 1; i <= n; i++)
	{
		dp[i] = 1;
		for (int j = 1; j < i; j++)
		{
			if (a[j] <= a[i]) dp[i] = max(dp[i], dp[j] + 1);
		}
		maxn = max(maxn, dp[i]);
	}

	int s = n + 1, t = n + 2;
	g1.init(s, t, t);
	g2.init(s, t, t);

	for (int i = 1; i <= n; i++)
	{
		for (int j = i + 1; j <= n; j++)
		{
			if ((a[i] <= a[j]) && (dp[i] + 1 == dp[j]))
			{
				g1.add_edge(i, j, 1);
				g2.add_edge(i, j, 1);
			}
		}
	}

	for (int i = 1; i <= n; i++)
	{
		if (dp[i] == 1)
		{
			g1.add_edge(s, i, 1);
			g2.add_edge(s, i, n);
		}
		if (dp[i] == maxn)
		{
			g1.add_edge(i, t, 1);
			g2.add_edge(i, t, n);
		}
	}

	cout << maxn << '\n';
	cout << g1.dinic() << '\n';
	if (maxn == 1) cout << n << '\n';
	else cout << g2.dinic() << '\n';
}