#include <iostream>
#include <queue>
#include <cstring>
#include <vector>

using namespace std;

int bank[500010];

struct edge
{
	int to, next;
}e[1000010];
int head[500010], head_scc[500010], tot = 0;

void add_edge(int h[], int from, int to)
{
	e[++tot].to = to;
	e[tot].next = h[from];
	h[from] = tot;
}

int timestamp = 0;
int scc_cnt = 0;
int dfn[500010], low[500010];
int stk[500010], top = 0;
bool in_stk[500010];
int scc_id[500010], scc_size[500010];
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
		int x;
		++scc_cnt;

		do {
			x = stk[top--];
			in_stk[x] = false;
			scc_id[x] = scc_cnt;
			scc_size[scc_cnt] += bank[x];
		} while (x != u);
	}
}

int dist[500010];
bool vis[500010];
void spfa(int st)
{
	memset(dist, 0, sizeof(dist));
	memset(vis, false, sizeof(vis));
	queue<int> q;

	q.push(st);
	dist[st] = scc_size[st];
	vis[st] = true;

	while (!q.empty())
	{
		int u = q.front();
		q.pop();
		vis[u] = false;

		for (int i = head_scc[u]; i; i = e[i].next)
		{
			int j = e[i].to;

			if (dist[j] < dist[u] + scc_size[j])
			{
				dist[j] = dist[u] + scc_size[j];

				if (!vis[j])
				{
					q.push(j);
					vis[j] = true;
				}
			}
		}
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


	for(int i = 1; i <= n; i++) cin >> bank[i];

	for (int i = 1; i <= n; i++)
	{
		if (!dfn[i]) tarjan(i);
	}

	int st, bar_cnt;
	cin >> st >> bar_cnt;

	vector<int> bar;
	for (int i = 1; i <= bar_cnt; i++)
	{
		int x;
		cin >> x;
		bar.push_back(scc_id[x]);
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = head[i]; j; j = e[j].next)
		{
			int k = e[j].to;

			int a = scc_id[i], b = scc_id[k];

			if (a != b) add_edge(head_scc, a, b);
		}
	}

	spfa(scc_id[st]);

	int res = 0;
	for (auto i : bar)
	{
		res = max(res, dist[i]);
	}

	cout << res << '\n';

	return 0;
}