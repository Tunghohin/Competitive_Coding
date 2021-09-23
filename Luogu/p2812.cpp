#include <iostream>

using namespace std;

int din[10010], dout[10010];

struct edge
{
	int to, next;
}e[5000010];
int head[10010], tot = 0;

void add_edge(int from, int to)
{
	e[++tot].to = to;
	e[tot].next = head[from];
	head[from] = tot;
}

int scc_cnt = 0;
int scc_id[10010];
int timestamp = 0;
int dfn[10010], low[10010];
int stk[10010], top = 0;
bool in_stk[10010];
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
		++scc_cnt;
		int x;

		do {
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
				dout[a]++;
				din[b]++;
			}
		}
	}

	int a = 0, b = 0;
	for (int i = 1; i <= scc_cnt; i++)
	{
		if (!din[i]) a++;
		if (!dout[i]) b++;
	}

	cout << a << '\n';
	if (scc_cnt == 1) cout << 0 << '\n';
	else cout << max(a, b) << '\n';

	return 0;
}