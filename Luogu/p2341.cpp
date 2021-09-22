#include <iostream>

using namespace std;

int out_degree[10010];

struct edge
{
	int to, next;
}e[100010];
int head[10010], tot = 0;

void add_edge(int from, int to)
{
	e[++tot].to = to;
	e[tot].next = head[from];
	head[from] = tot;
}

int scc_cnt = 0;
int scc_id[10010];
int scc_size[10010];
int timestamp = 0;
int dfn[10010], low[10010];
int stk[10010], top = 0;
int in_stk[10010];
void tarjan(int u)
{
	dfn[u] = low[u] = ++timestamp;
	stk[++top] = u, in_stk[u] = true;

	for (int i = head[u]; i; i = e[i].next)
	{
		int j = e[i].to;

		if (!dfn[j])
		{
			tarjan(j);
			low[u] = min(low[u], low[j]);
		}

		else if (in_stk[u]) low[u] = min(low[u], dfn[j]);
	}

	if (dfn[u] == low[u])
	{
		++scc_cnt;
		int x;

		do {
			x = stk[top--];
			in_stk[x] = false;
			scc_id[x] = scc_cnt;
			scc_size[scc_cnt]++;
		}while (x != u);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int n, m;
	cin >> n >> m;

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
		for (int j = head[i]; j; j = e[j].next)
		{
			int k = e[j].to;

			int a = scc_id[i], b = scc_id[k];

			if (a != b) out_degree[a]++;
		}
	}

	int ends = 0, res = 0;
	for (int i = 1; i <= scc_cnt; i++)
	{
		if (!out_degree[i])
		{
			ends++;
			res += scc_size[i];

			if (ends > 1)
			{
				res = 0;
				break;
			}
		}
	}

	cout << res << '\n';

	return 0;
}