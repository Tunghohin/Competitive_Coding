#include <iostream>

using namespace std;

const int N = 1000010;

int prefix_xor[N];
int trie_01[6 * N][2], idx = 0;

struct edge
{
	int to, val, next;
}e[N * 2];
int head[N], tot = 0;

void add_edge(int from, int to, int val)
{
	e[++tot].to = to;
	e[tot].val = val;
	e[tot].next = head[from];
	head[from] = tot;
}

void dfs(int u, int from)
{
	for (int i = head[u]; i; i = e[i].next)
	{
		int j = e[i].to;
		if (j == from) continue;

		dfs(j, u);
		prefix_xor[j] = prefix_xor[u] ^ e[i].val;
	}
}

void insert(int x)
{
	int p = 0;
	for (int i = 30; i >= 0; i--)
	{
		int &u = trie_01[p][x >> i & 1];
		if (!u) u = ++idx;
		p = u;
	}
}

int get(int x)
{
	int p = 0, res = 0;

	for (int i = 30; i >= 0; i--)
	{
		int u = x >> i & 1;
		if (trie_01[p][u ^ 1])
		{
			res += 1 << i;
			p = trie_01[p][u ^ 1];
		}
		else p = trie_01[p][u];
	}

	return res;
}

int main()
{
	int n;
	cin >> n;

	for (int i = 1; i < n; i++)
	{
		int a, b, v;
		cin >> a >> b >> v;
		add_edge(a, b, v), add_edge(b, a, v);
	}

	dfs(1, 0);

	for (int i = 1; i <= n; i++) insert(prefix_xor[i]);

	int res = 0;
	for (int i = 1; i <= n; i++) res = max(res, get(prefix_xor[i]));

	cout << res << '\n';
}