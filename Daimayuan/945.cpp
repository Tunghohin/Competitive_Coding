#include <iostream>
#include <vector>

using namespace std;

const int N = 1000010;
const int M = N;
int n, m;
int MOD;

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

	int scc_id[N];
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
				scc_id[x] = scc_cnt;
				in_stk[x] = false;
				SCC[scc_cnt].push_back(x);
			} while (x != u);
		}
	}

	int dp[N], way_cnt[N];
	bool vis[N];
	void get_res()
	{
		for (int i = 1; i <= n; i++)
		{
			if (!dfn[i]) tarjan(i);
		}

		int ans = 0, cnt = 0;
		for (int i = 1; i <= scc_cnt; i++)
		{
			way_cnt[i] = 1;
			dp[i] = 0;
			for (auto u : SCC[i])
			{
				for (int j = head[u]; j; j = e[j].next)
				{
					int v = e[j].to;
					if (!vis[scc_id[v]] && scc_id[v] != i)
					{
						vis[scc_id[v]] = true;
						if (dp[scc_id[v]] > dp[i]) dp[i] = dp[scc_id[v]], way_cnt[i] = 0;
						if (dp[scc_id[v]] == dp[i]) way_cnt[i] = (way_cnt[i] + way_cnt[scc_id[v]]) % MOD;
					}
				}
			}
			dp[i] += SCC[i].size();
			if (dp[i] > ans) ans = dp[i], cnt = 0;
			if (dp[i] == ans) cnt = (cnt + way_cnt[i]) % MOD;
			for (auto u : SCC[i])
			{
				for (int j = head[u]; j; j = e[j].next) vis[scc_id[e[j].to]] = false;
			}
		}

		cout << ans << '\n' << cnt << '\n';
	}
};
graph<int> g;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	cin >> n >> m >> MOD;

	for (int i = 1; i <= m; i++)
	{
		int u, v;
		cin >> u >> v;
		g.add_edge(u, v);
	}

	g.get_res();
}