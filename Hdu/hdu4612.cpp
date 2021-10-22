#include <iostream>
#include <algorithm>
#include <unordered_set>


#pragma comment(linker, "/STACK:1024000000,1024000000")

using namespace std;

const int N = 200010, M = 3000010;

struct edge
{
	int from, to, next;
}e[2 * M];
int head[N], head_bcc[N], tot = 0;

void add_edge(int h[], int from, int to)
{
	e[++tot].to = to;
	e[tot].from = from;
	e[tot].next = h[from];
	h[from] = tot;
}

int inv_edge(int i)
{
	return i - ((i ^ 1) - i);
}

int dfn[N], low[N], timestamp = 0;
int stk[N], top = 0;
bool in_stk[N];
int bcc_id[N], bcc_cnt;
void tarjan(int u, int from)
{
	dfn[u] = low[u] = ++timestamp;
	stk[++top] = u, in_stk[u] = true;

	for (int i = head[u]; i; i = e[i].next)
	{
		int j = e[i].to;
		if (from == i) continue;

		if (!dfn[j])
		{
			tarjan(j, i);
			low[u] = min(low[u], low[j]);
		}

		else if (i != inv_edge(from)) low[u] = min(low[u], dfn[j]);
	}

	if (dfn[u] == low[u])
	{
		++bcc_cnt;
		int x;

		do
		{
			x = stk[top--];
			bcc_id[x] = bcc_cnt;
			in_stk[x] = false;
		} while (x != u);
	}
}

bool cmp(edge a, edge b)
{
	if (bcc_id[a.from] == bcc_id[b.from]) return a.to < b.to;
	else return bcc_id[a.from] < bcc_id[b.from];
}

void init(int a[], int n)
{
	for (int i = 0; i <= n; i++) a[i] = 0;
}

int mx[N], smx[N];
void dfs(int u, int from)
{
	mx[u] = smx[u] = 0;
	for (int i = head_bcc[u]; i; i = e[i].next)
	{
		int j = e[i].to;

		if (j == from) continue;

		dfs(j, u);

		int tmp = mx[j] + 1;
		if (tmp >= mx[u])
		{
			smx[u] = mx[u];
			mx[u] = tmp;
		}

		else if (tmp > smx[u])
		{
			smx[u] = tmp;
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int n, m;
	while (cin >> n >> m, n || m)
	{
		init(head, n);
		init(head_bcc, n);
		init(dfn, n);
		init(bcc_id, n);
		tot = timestamp = bcc_cnt = top = 0;

		for (int i = 1; i <= m; i++)
		{
			int a, b;
			cin >> a >> b;

			add_edge(head, a, b), add_edge(head, b, a);
		}

		tarjan(1, -1);

		if (bcc_cnt == 1)
		{
			cout << -1 << '\n';
			continue;
		}


		for (int i = 1; i <= n; i++)
		{
			for (int j = head[i]; j; j = e[j].next)
			{
				int k = e[j].to;

				int a = bcc_id[i], b = bcc_id[k];
				if (a != b)
				{
					add_edge(head_bcc, a, b);
				}
			}
		}


		dfs(1, -1);

		int longest_path = -1;
		for (int i = 1; i <= bcc_cnt; i++) longest_path = max(longest_path, mx[i] + smx[i]);

		cout << bcc_cnt - 1 - longest_path << '\n';
	}
}