#include <iostream>
#include <vector>

using namespace std;

const int N = 2010, M = 2010; //2000010

struct edge
{
	int to, next;
}e[M];
int head[N], tot = 0;

void add_edge(int from, int to)
{
	e[++tot].to = to;
	e[tot].next = head[from];
	head[from] = tot;
}

int dfn[N], low[N], timestamp = 0;
int stk[N], top = 0;
bool in_stk[N];
int scc_id[N];
int scc_cnt = 0;
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

	if (low[u] == dfn[u])
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
		if (scc_id[i] == scc_id[i + 1]) return false;
	}

	return true;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= m; i++)
	{
		int a, va, b, vb;
		cin >> a >> va >> b >> vb;

		add_edge(2 * a - (va), 2 * b - !(vb));
		add_edge(2 * b - (vb), 2 * a - !(va));
	}

	if (!two_sat(n)) cout << "IMPOSSIBLE\n";
	else
	{
		cout << "POSSIBLE\n";
		for (int i = 1; i <= 2 * n; i += 2)
		{
			if (scc_id[i] > scc_id[i + 1]) cout << 1 << ' ';
			else cout << 0 << ' ';
		}
	}
}