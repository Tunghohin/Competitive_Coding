#include <iostream>

using namespace std;

const int N = 100010;

struct edge
{
	int to, next;
}e[N];
int head[N], tot = 0;
int in_d[N], out_d[N];

void add_edge(int from, int to)
{
	e[++tot].to = to;
	e[tot].next = head[from];
	head[from] = tot;
}

int dfn[N], low[N], timestamp = 0;
int stk[N], top;
bool in_stk[N];
int scc_cnt = 0;
int scc_id[N];
int scc_size[N];
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

	if (low[u] == dfn[u])
	{
		int x;
		++scc_cnt;

		do
		{
			x = stk[top--];
			in_stk[x] = false;
			scc_id[x] = scc_cnt;
			scc_size[scc_cnt]++;
		} while (x != u);
	}
}

void init(int n)
{
	for (int i = 0; i <= n; i++)
	{
		dfn[i] = low[i] = 0;
		scc_id[i] = scc_size[i] = 0;
		in_stk[i] = false;
		head[i] = 0;
		in_d[i] = out_d[i] = 0;
	}

	timestamp = scc_cnt = tot = 0;
}

void solve(int cast_cnt)
{
	int n, m;
	cin >> n >> m;

	init(n);

	for (int i = 1; i <= m; i++)
	{
		int f, t;
		cin >> f >> t;
		add_edge(f, t);
	}

	for (int i = 1; i <= n; i++)
	{
		if (!dfn[i]) tarjan(i);
	}

	int ans = n * (n - 1) - m;

	for (int i = 1; i <= n; i++)
	{
		for (int j = head[i]; j; j = e[j].next)
		{
			int k = e[j].to;

			if (scc_id[i] != scc_id[k])
			{
				in_d[scc_id[k]]++;
				out_d[scc_id[i]]++;
			}
		}
	}

	int min_scc = 0x3f3f3f3f;
	for (int i = 1; i <= scc_cnt; i++)
	{
		if (!in_d[i] || !out_d[i])
		{
			min_scc = min(min_scc, scc_size[i]);
		}
	}

	cout << "Case " << cast_cnt << ": ";
	if (scc_cnt == 1) cout << -1 << '\n';
	else cout << ans - min_scc * (n - min_scc) << '\n';
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int T;
	cin >> T;

	for (int i = 1; i <= T; i++)
	{
		solve(i);
	}
}