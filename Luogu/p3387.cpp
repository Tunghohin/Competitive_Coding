#include <iostream>

using namespace std;

int weight[10010];
int in_degree[10010];

struct edge
{
	int to, next;
}edg[100010], edg_scc[100010];
int head[10010], tot = 0;
int head_scc[10010], tot_scc = 0;

void add_edge(int from, int to)
{
	edg[++tot].to = to;
	edg[tot].next = head[from];
	head[from] = tot;
}

void add_edge_scc(int from, int to)
{
	edg_scc[++tot_scc].to = to;
	edg_scc[tot_scc].next = head_scc[from];
	head_scc[from] = tot_scc;
}

int scc_cnt = 0;
int scc_id[10010];
int scc_size[10010];
int timestamp = 0;
int dfn[10010], low[10010];
int stk[10010], top = 0;
bool in_stk[10010];
void tarjan(int u)
{
	dfn[u] = low[u] = ++timestamp;
	stk[++top] = u, in_stk[u] = true;

	for (int i = head[u]; i; i = edg[i].next)
	{
		int j = edg[i].to;

		if (!dfn[j])
		{
			tarjan(j);
			low[u] = min(low[u], low[j]);
		}

		else if (in_stk[j]) low[u] = min(low[u], dfn[j]);
	}

	if (dfn[u] == low[u])
	{
		scc_cnt++;
		int x;

		do
		{
			x = stk[top--];
			in_stk[x] = false;
			scc_id[x] = scc_cnt;
			scc_size[scc_cnt] += weight[x];
		} while (x != u);
	}
}

int dp[10010];
bool vis[10010];
int dfs(int u)
{
	if (vis[u]) return dp[u];

	vis[u] = true;
	dp[u] = scc_size[u];

	int maxn = 0;
	for (int i = head_scc[u]; i; i = edg_scc[i].next)
	{
		int j = edg_scc[i].to;

		maxn = max(maxn, dfs(j));
	}

	dp[u] += maxn;
	return dp[u];
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= n; i++) cin >> weight[i];

	for (int i = 1; i <= m; i++)
	{
		int a, b;
		cin >> a >> b;
		add_edge(a, b);
	}

	for (int i = 1; i <= n; i++)
	{
		if (!dfn[i]) tarjan(i);
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = head[i]; j; j = edg[j].next)
		{
			int k = edg[j].to;

			int a = scc_id[i], b = scc_id[k];

			if (a != b) add_edge_scc(a, b);
		}
	}

	int res = 0;
	for (int i = 1; i <= scc_cnt; i++)
	{
		if (!vis[i])
		{
			res = max(res, dfs(i));
		}
	}

	cout << res << '\n';
}