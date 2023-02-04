#include <bits/stdc++.h>
#define int long long

using namespace std;
using LL = long long;
using ULL = unsigned long long;
using PII = pair<int, int>;
using PLI = pair<long long, int>;
using PLL = pair<long long, long long>;

const int N = 100010;

int st[N], u[N];
int dg[N];

struct graph
{
	struct edge
	{
		int to, next;
		int weight;
	} e[N];
	int head[N], tot = 0;

	void add_edge(int from, int to, int weight)
	{
		e[++tot].to = to;
		e[tot].weight = weight;
		e[tot].next = head[from];
		head[from] = tot; 
	}
};
graph g;

void solve()
{
	int n, p;
	cin >> n >> p;

	for (int i = 1; i <= n; i++)
	{
		cin >> st[i] >> u[i];
	}

	for (int i = 1; i <= p; i++)
	{
		int u, v, val;
		cin >> u >> v >> val;

		g.add_edge(u, v, val);
		dg[v]++;
	}

	queue<int> que;
	for (int i = 1; i <= n; i++)
	{
		if (dg[i] == 0) que.push(i), st[i] += u[i];
	}

	while (!que.empty())
	{
		auto node = que.front();
		st[node] -= u[node];
		if (st[node] < 0) st[node] = 0;
		que.pop();

		for (int i = g.head[node]; i; i = g.e[i].next)
		{
			int j = g.e[i].to;
			st[j] += g.e[i].weight * st[node];
			dg[j]--;
			if (dg[j] == 0) que.push(j);
		}
	}

	for (int i = 1; i <= n; i++)
	{
		cout << st[i] << ' ' << '\n';
	}

	int found = false;
	for (int i = 1; i <= n; i++)
	{
		if (g.head[i] == 0 && st[i] != 0)
		{
			found = true;
			cout << i << ' ' << st[i] << '\n';
		}
	}
	if (!found) cout << "NULL\n";
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	T = 1;

	while (T--)
	{
		solve();
	}
}