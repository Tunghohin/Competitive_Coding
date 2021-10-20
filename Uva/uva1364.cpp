#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

const int N = 1010;

bool G[N][N];
bool meeting_enabled[N];

struct edge
{
	int to, next;
}e[200];
int head[N], tot = 0;

void add_edge(int from ,int to)
{
	e[++tot].to = to;
	e[tot].next = head[from];
	head[from] = tot;
}

int root;
int dfn[N], low[N], timestamp = 0;
int stk[N], top = 0;
int bcc_cnt = 0;
vector<int> bcc[N];
void tarjan(int u)
{
	low[u] = dfn[u] = ++timestamp;
	stk[++top] = u;

	if (u == root && !head[u])
	{
		bcc[++bcc_cnt].push_back(u);
		return;
	}

	for (int i = head[u]; i; i = e[i].next)
	{
		int j = e[i].to;

		if (!dfn[j])
		{
			tarjan(j);
			low[u] = min(low[u], low[j]);

			if (dfn[u] <= low[j])
			{
				++bcc_cnt;
				int x;

				do
				{
					x = stk[top--];
					bcc[bcc_cnt].push_back(x);
				} while (x != j);
				bcc[bcc_cnt].push_back(u);
			}
		}

		else low[u] = min(low[u], dfn[j]);
	}
}

int color[N];
bool in_bcc[N];
bool dfs(int u, int type)
{
	color[u] = type;

	for (int i = head[u]; i; i = e[i].next)
	{
		int j = e[i].to;
		if (!in_bcc[j]) continue;

		if (!color[j])
		{
			if (!dfs(j, 3 - type)) return false;
		}
		else if (color[j] == type) return false;
	}

	return true;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int n, m;
	while (cin >> n >> m, n || m)
	{
		memset(G, false, sizeof(G));
		memset(dfn, 0, sizeof(dfn));
		memset(low, 0, sizeof(low));
		memset(meeting_enabled, false, sizeof(enable_meeting));
		memset(head, 0, sizeof(head));
		tot = timestamp = top = bcc_cnt = 0;

		while (m--)
		{
			int a, b;
			cin >> a >> b;
			G[a][b] = G[b][a] = true;
		}

		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j < i; j++)
			{
				if (!G[i][j]) add_edge(i, j), add_edge(j, i);
			}
		}

		for (root = 1; root <= n; root++)
		{
			if (!dfn[root]) tarjan(root);
		}

		for (int i = 1; i <= bcc_cnt; i++)
		{
			memset(color, 0, sizeof(color));
			memset(in_bcc, false, sizeof(in_bcc));

			for (auto u : bcc[i]) in_bcc[u] = true;

			if (!dfs(bcc[i].front(), 1))
			{
				for (auto u : bcc[i]) meeting_enabled[u] = true;
			}
		}

		int res = 0;
		for (int i = 1; i <= n; i++) if (!meeting_enabled[i]) res++;

		cout << res << '\n';
	}
}