#include <iostream>

using namespace std;

int in_degree[100010], out_degree[100010];

struct edge
{
	int to, next;
}e[300010];
int head[100010], tot = 0;

void add_edge(int h[], int from, int to)
{
	e[++tot].to = to;
	e[tot].next = h[from];
	h[from] = tot;
}

int timestamp = 0;
int scc_cnt = 0;
int dfn[100010], low[100010];
int stk[100010], top = 0;
bool in_stk[100010];
int scc_id[100010], scc_size[100010];
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

		else if (in_stk[j]) low[u] = min(low[u], dfn[j]);
	}

	if (dfn[u] == low[u])
	{
		scc_cnt++;

		int x;

		do {
			x = stk[top--];
			in_stk[x] = false;
			scc_id[x] = scc_cnt;
			scc_size[scc_cnt]++;
		} while (x != u);
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
		add_edge(head, a, b);
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

			if (a != b)
			{
				in_degree[b]++;
				out_degree[a]++;
			}
		}
	}

	int res_1 = 1;
	for (int i = 1; i <= scc_cnt; i++) res_1 = max(res_1, scc_size[i]);

	int a = 0, b = 0;
	for (int i = 1; i <= scc_cnt; i++)
	{
		if (!in_degree[i]) a++;
		if (!out_degree[i]) b++;
	}

	cout << res_1 << '\n';
	if (scc_cnt == 1) cout << 0;
	else cout << max(a, b);

	return 0;
}