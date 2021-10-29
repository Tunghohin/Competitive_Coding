#include <iostream>
#include <cmath>

using namespace std;

const int N = 100010;

int val[N];
int prefix_xor[N];

struct edge
{
	int to, next;
}e[2 * N];
int head[N], tot = 0;

void add_edge(int from, int to)
{
	e[++tot].to = to;
	e[tot].next = head[from];
	head[from] = tot;
}

int depth[N];
int f[N][15];
int in_stamp[N], out_stamp[N], timestamp = 0;
int dfn[N];
void dfs(int u, int from)
{
	depth[u] = depth[from] + 1;
	f[u][0] = from;
	for (int i = 1; i <= 15; i++) f[u][i] = f[f[u][i - 1]][i - 1];
	in_stamp[u] = ++timestamp;
	dfn[timestamp] = u;

	for (int i = head[u]; i; i = e[i].next)
	{
		int j = e[i].to;
		if (j == from) continue;

		prefix_xor[j] = prefix_xor[u] ^ val[j];
		dfs(j, u);
	}

	out_stamp[u] = timestamp;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int n, q;
	cin >> n >> q;

	for (int i = 1; i <= n; i++) cin >> val[i];

	for (int i = 1; i < n; i++)
	{
		int a, b;
		cin >> a >> b;
		add_edge(a, b), add_edge(b, a);
	}

	dfs(1, -1);

	int op;
	while (q--)
	{
		cin >> op;
		if (op == 1)
		{

		}
		else
		{

		}
	}
}