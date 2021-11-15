#include <iostream>
#include <cstring>

using namespace std;

const int N = 100010, M = 100010;

double eps = 1e-8;

int age[N];

struct edge
{
	int to, next;
}e[4 * M];
int head[2 * N], tot = 0;

void add_edge(int from, int to)
{
	e[++tot].to = to;
	e[tot].next = head[from];
	head[from] = tot;
}

int dfn[2 * N], low[2 * N], timestamp = 0;
int stk[2 * N], top = 0;
bool in_stk[2 * N];
int scc_cnt;
int scc_id[2 * N];
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
		else if (in_stk[j]) low[u] = min(low[u], dfn[j]);
	}

	if (dfn[u] == low[u])
	{
		int x;
		scc_cnt++;

		do
		{
			x = stk[top--];
			in_stk[x] = false;
			scc_id[x] = scc_cnt;
		} while (x != u);
	}
}

bool two_sat(int n)
{
	for (int i = 1; i <= 2 * n; i++)
	{
		if (!dfn[i]) tarjan(i);
	}

	for (int i = 1; i <= 2 * n; i += 2)
	{
		if (scc_id[i] == scc_id[i + 1])
		{
			return false;
		}
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
		memset(dfn, 0, sizeof(dfn));
		memset(head, 0, sizeof(head));
		memset(scc_id, 0, sizeof(scc_id));
		memset(in_stk, false, sizeof(in_stk));
		tot = top = timestamp = scc_cnt = 0;

		int sum = 0;
		for (int i = 1; i <= n; i++)
		{
			cin >> age[i];
			sum += age[i];
		}

		for (int i = 1; i <= m; i++)
		{
			int a, b;
			cin >> a >> b;
			if (a == b) continue;

			add_edge(2 * a, 2 * b - 1);
			add_edge(2 * b, 2 * a - 1);

			if (age[a] * n >= sum == age[b] * n >= sum)
			{
				add_edge(2 * a - 1, 2 * b);
				add_edge(2 * b - 1, 2 * a);
			}
		}

		if (!two_sat(n))
		{
			cout << "No solution.\n";
			continue;
		}

		for (int i = 1; i <= 2 * n; i += 2)
		{
			if (scc_id[i] > scc_id[i + 1]) cout << "C\n";
			else
			{
				if (age[(i + 1) / 2] * n >= sum) cout << "A\n";
				else cout << "B\n";
			}
		}
	}
}