#include <sstream>
#include <iostream>
#include <queue>
#include <limits>
#include <vector>

using namespace std;

const long long inf = 0x3f3f3f3f3f3f3f3f;
const int N = 1010;
const int E = 200010;
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

FlowGraph<long long> g;
vector<int> expm[53];
vector<int> inst_cost(53);
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int m, n;
	cin >> m >> n;

	int s = n + m + 1, t = s + 1;
	g.init(s, t, t);

	string str;
	getline(cin, str);
	for (int i = 1; i <= m; i++)
	{
		getline(cin, str);
		stringstream ss;
		ss << str;

		while (!ss.eof())
		{
			int x;
			ss >> x;
			expm[i].push_back(x);
		}
	}
	for (int i = 1; i <= n; i++) cin >> inst_cost[i];

	long long tot = 0;
	for (int i = 1; i <= m; i++)
	{
		bool flag = false;
		for (auto u : expm[i])
		{
			if (!flag)
			{
				tot += u;
				g.add_edge(s, i, u);
				flag = true;
			}
			else
			{
				g.add_edge(i, m + u, inf);
			}
		}
	}

	for (int i = 1; i <= n; i++)
	{
		g.add_edge(i + m, t, inst_cost[i]);
	}

	long long res = tot - g.dinic();
	for (int i = 1; i <= m; i++)
	{
		if (g.dis[i]) cout << i << ' ';
	}
	cout << '\n';
	for (int i = 1; i <= n; i++)
	{
		if (g.dis[i + m]) cout << i << ' ';
	}
	cout << '\n';
	cout << res << '\n';
}