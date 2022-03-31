#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

const int N = 100010;

long long val[N];
int ti[N];
long long f[N], h[N];

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

void dfs(int u, int from)
{
	long long s = 0;
	long long maxn = 0;
	for (int i = head[u]; i; i = e[i].next)
	{
		int to = e[i].to;
		if (to == from) continue;
		dfs(to, u);
		s += f[to];
		maxn = max(maxn, val[to]);
	}

	f[u] = maxn + s;

	pair<long long, int> mx(-0x3f3f3f3f, 0), smx(-0x3f3f3f3f, 0);
	for (int i = head[u]; i; i = e[i].next)
	{
		int to = e[i].to;
		if (to == from || ti[to] != 3) continue;
		pair<long long, int> tmp(val[to], to);
		if (tmp > smx)  smx = tmp;
		if (smx > mx) swap(smx, mx);
	}

	for (int i = head[u]; i; i = e[i].next)
	{
		int to = e[i].to;
		if (to == from) continue;

		long long tmp = s + h[to] - f[to];
		if (to == mx.second) tmp += smx.first;
		else tmp += mx.first;
		f[u] = max(f[u], tmp);
	}

	h[u] = s + val[u];
}

void solve()
{
	int n;
	cin >> n;

	tot = 0;
	for (int i = 0; i <= n; i++) head[i] = h[i] = f[i] = 0;

	for (int i = 1; i <= n; i++) cin >> val[i];
	for (int i = 1; i <= n; i++) cin >> ti[i];

	for (int i = 1; i < n; i++)
	{
		int a, b;
		cin >> a >> b;
		add_edge(a, b), add_edge(b, a);
	}

	dfs(1, 0);

	cout << f[1] + val[1] << '\n';
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int T;
	cin >> T;

	while (T--)
	{
		solve();
	}
}