#include <iostream>

using namespace std;

const int N = 200020;

typedef long long LL;

int n, q;
int timestamp;
int L[N], R[N];
LL tr1[N], tr2[N];
LL val[N];

struct edge
{
	int to, next;
}e[2 * N];
int head[N], tot;

void add_edge(int from, int to)
{
	e[++tot].to = to;
	e[tot].next = head[from];
	head[from] = tot;
}

int low_bit(int x)
{
	return x & (-x);
}

void modify(int x, LL v, LL tr[])
{
	for (;x <= n + 1; x += low_bit(x))
	{
		tr[x] += v;
	}
}

LL query(int x, LL tr[])
{
	LL res = 0;
	for (; x; x -= low_bit(x))
	{
		res += tr[x];
	}
	return res;
}

void dfs(int u, int from)
{
	L[u] = ++timestamp;
	for (int i = head[u]; i; i = e[i].next)
	{
		int j = e[i].to;
		if (j == from) continue;

		dfs(j, u);
	}
	R[u] = timestamp;
}

void solve()
{
	cin >> n >> q;

	for (int i = 1; i < n; i++)
	{
		int a, b;
		cin >> a >> b;
		add_edge(a, b);
		add_edge(b, a);
	}

	dfs(1, 0);

	for (int i = 1; i <= n; i++)
	{
		LL x;
		cin >> x;
		val[i] = x;

		modify(L[i], x, tr1);
		modify(L[i], x, tr2);
		modify(R[i] + 1, -x, tr2);
	}

	for (int i = 1; i <= q; i++)
	{
		int op;
		cin >> op;

		if (op == 1)
		{
			int x;
			LL y;
			cin >> x >> y;

			modify(L[x], (y - val[x]), tr1);
			modify(L[x], (y - val[x]), tr2);
			modify(R[x] + 1, -(y - val[x]), tr2);

			val[x] = y;
		}
		else
		{
			int x;
			cin >> x;

			cout << query(R[x], tr1) - query(L[x] - 1, tr1) << ' ';
			cout << query(L[x], tr2) << '\n';
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	solve();
}