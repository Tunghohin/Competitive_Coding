#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;
using LL = long long;

const int N = 2010;

int n, num;
LL dp[N][N];
int sz[N];

template<typename T>
class tree {
public:
	struct edge
	{
		int to, next;
		T val;
	} e[2 * N];
	int head[N], tot = 0;

	void add_edge(int from, int to, T val)
	{
		e[++tot] = {to, head[from], val}; head[from] = tot;
	}
};
tree<LL> tr;

void dfs(int u, int from)
{
	sz[u] = 1;
	dp[u][0] = dp[u][1] = 0;

	for (int i = tr.head[u]; i; i = tr.e[i].next)
	{
		int v = tr.e[i].to;
		if (v == from) continue;
		dfs(v, u);

		sz[u] += sz[v];
		for (int j = min(num, sz[u]); j >= 0; j--)
		{
			if (dp[u][j] != -1)
			{
				dp[u][j] += dp[v][0] + (LL)sz[v] * (n - num - sz[v]) * tr.e[i].val;
			}
			for (int k = min(j, sz[v]); k; k--)
			{
				if (dp[u][j - k] == -1) continue;
				LL val = (LL)(k * (num - k) + (sz[v] - k) * (n - num - sz[v] + k)) * tr.e[i].val;
				dp[u][j] = max(dp[u][j], dp[u][j - k] + dp[v][k] + val); 
			}
		}
	}
}

void solve()
{
	cin >> n >> num;

	for (int i = 1; i < n; i++)
	{
		int f, t, v;
		cin >> f >> t >> v;
		tr.add_edge(f, t, v);
		tr.add_edge(t, f, v);
	}

	memset(dp, -1, sizeof(dp));

	dfs(1, 0);
	cout << dp[1][num];
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	solve();
}