#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;
using LL = long long;

const int N = 500010;

LL dp[N][2]; //0 tot, 1 need add
int n, st;

template<typename T>
class tree {
public:
	struct edge
	{
		int to, next;
		T val;
	} e[2 * N];
	int head[N], tot;

	void add_edge(int from, int to, T val)
	{
		e[++tot] = {to, head[from], val}; head[from] = tot;
	}
};
tree<long long> tr;

void dfs(int u, int from)
{
	dp[u][0] = 0;
	LL max_v = 0;
	for (int i = tr.head[u]; i; i = tr.e[i].next)
	{
		int v = tr.e[i].to;
		if (v == from) continue;
		dfs(v, u);

		max_v = max(max_v, tr.e[i].val + dp[v][0]);
	}

	dp[u][0] = max_v;
	for (int i = tr.head[u]; i; i = tr.e[i].next)
	{
		int v = tr.e[i].to;
		if (v == from) continue;
		dp[u][1] += dp[u][0] - (tr.e[i].val + dp[v][0]);
	}
}

void solve()
{
	cin >> n;
	cin >> st;

	for (int i = 1; i < n; i++)
	{
		int u, v, t;
		cin >> u >> v >> t;
		tr.add_edge(u, v, t), tr.add_edge(v, u, t);
	}

	dfs(st, 0);

	LL tot = 0;
	for (int i = 1; i <= n; i++)
	{
		tot += dp[i][1];
	}

	cout << tot << '\n';
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	solve();
}