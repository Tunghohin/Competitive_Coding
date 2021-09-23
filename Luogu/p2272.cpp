#include <iostream>
#include <unordered_set>

using namespace std;

int mod;
int f[100010], g[100010];

struct edge
{
	int to, next;
}e[2000010];
int head[100010], head_scc[100010], tot = 0;

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
		int x;
		++scc_cnt;

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
	cin >> n >> m >> mod;

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

	unordered_set<long long> S;
	for (int i = 1; i <= n; i++)
	{
		for (int j = head[i]; j; j = e[j].next)
		{
			int k = e[j].to;
			int a = scc_id[i], b = scc_id[k];
			long long hash = a * 1000000ll + b;

			if (a != b && !S.count(hash))
			{
				add_edge(head_scc, a, b);
				S.insert(hash);
			}
		}
	}

	for (int i = scc_cnt; i; i--)
	{
		if (!f[i])
		{
			f[i] = scc_size[i];
			g[i] = 1;
		}

		for (int j = head_scc[i]; j; j = e[j].next)
		{
			int k = e[j].to;

			if (f[k] < f[i] + scc_size[k])
			{
				f[k] = f[i] + scc_size[k];
				g[k] = g[i];
			}

			else if (f[k] == f[i] + scc_size[k])
			{
				g[k] = (g[i] + g[k]) % mod;
			}
		}
	}

	int maxf = 0, sum = 0;

	for (int i = 1; i <= scc_cnt; i++)
	{
		if (f[i] > maxf)
		{
			maxf = f[i];
			sum = g[i];
		}

		else if (f[i] == maxf) sum = (sum + g[i]) % mod;
	}

	cout << maxf << '\n';
	cout << sum << '\n';

	return 0;
}