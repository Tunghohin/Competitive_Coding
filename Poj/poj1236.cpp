#include <iostream>
#define nullptr 0

using namespace std;

const int N = 110;

int in_degree[N], out_degree[N];

struct edge
{
	int to, next;
}e[1000010];
int head[N], tot = 0;

void add_edge(int from, int to)
{
	e[++tot].to = to;
	e[tot].next = head[from];
	head[from] = tot;
}

int dfn[N], low[N], timestamp;
int stk[N], top = 0;
bool in_stk[N];
int scc_cnt, scc_id[N];
void tarjan(int u)
{
	low[u] = dfn[u] = ++timestamp;
	stk[++top] = u, in_stk[u] = true;

	for (int i = head[u]; i; i = e[i].next)
	{
		int j = e[i].to;

		if (!dfn[j])
		{
			tarjan(j);
			low[u] = min(low[u], low[j]);
		}

		else if (in_stk[j]) low[u] = min(low[u], low[j]);
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
		} while (x != u);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int n;
	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		int x;
		while (cin >> x, x)
		{
			add_edge(i, x);
		}
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

	int a = 0, b = 0;
	for (int i = 1; i <= scc_cnt; i++)
	{
		if (in_degree[i] == 0) a++;
		else if (out_degree[i] == 0) b++;
	}

	cout << a << '\n';
	if (scc_cnt == 1) cout << 0 << '\n';
	else cout << max(a, b) << '\n';
}