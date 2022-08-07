#include <iostream>
#include <vector>

using namespace std;

int n, m;
const int N = 10010;
const int M = 50010;

template<typename T>
class graph
{
private:
	struct edge
	{
		int to, next;
	}e[M];
	int head[N], tot;

public:
	void add_edge(int from, int to)
	{
		e[++tot] = {to, head[from]}; head[from] = tot;
	}

	int scc_cnt = 0;
	int dfn[N], low[N], timestamp = 0;
	int stk[N], top = 0;
	bool in_stk[N];
	vector<int> SCC[N];
	void tarjan(int u)
	{
		dfn[u] = low[u] = ++timestamp;
		stk[++top] = u, in_stk[u] = true;

		for (int i = head[u]; i; i = e[i].next)
		{
			int v = e[i].to;
			if (!dfn[v])
			{
				tarjan(v);
				low[u] = min(low[u], low[v]);
			}
			else if (in_stk[v]) low[u] = min(low[u], dfn[v]);
		}

		if (dfn[u] == low[u])
		{
			++scc_cnt;
			int x;
			do {
				x = stk[top--];
				in_stk[x] = false;
				SCC[scc_cnt].push_back(x);
			} while (x != u);
		}
	}
};
graph<int> g;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	cin >> n >> m;

	for (int i = 1; i <= m; i++)
	{
		int u, v;
		cin >> u >> v;
		g.add_edge(u, v);
	}

	for (int i = 1; i <= n; i++)
	{
		if (!g.dfn[i]) g.tarjan(i);
	}

	long long res = 0;
	for (int i = 1; i <= g.scc_cnt; i++)
	{
		if (g.SCC[i].size() > 1) res++;
	}

	cout << res << '\n';
}