#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#define int long long

using namespace std;
using LL = long long;

const int N = 100010;

int tot = 0;
int n;
int sz[N];
int weight[N];
LL dp1[N];
LL dp2[N];

template<typename T>
class Tree {
public:
	struct edge
	{
		int to, next;
		T val;
	} e[2 * N];
	int head[N], tot = 0;

	int inv_edge(int x)
	{
		return x % 2 == 0? x - 1 : x + 1;
	}

	void add_edge(int from, int to, T val)
	{
		e[++tot] = {to, head[from], val}; head[from] = tot;
	}
};
Tree<long long> tr;

void dfs_1(int u, int from)
{
	sz[u] = weight[u];
	for (int i = tr.head[u]; i; i = tr.e[i].next)
	{
		int v = tr.e[i].to;
		if (v == from) continue;
		dfs_1(v, u);
		sz[u] += sz[v];
		dp1[u] += dp1[v] + (sz[v] * tr.e[i].val);
	}
}

void dfs_2(int u, int from)
{
	for (int i = tr.head[u]; i; i = tr.e[i].next)
	{
		int v = tr.e[i].to;
		if (v == from) continue;

		int val = tr.e[i].val;

		dp2[v] = dp2[u] + dp1[u] - dp1[v] - sz[v] * val + (sz[1] - sz[v]) * val;

		dfs_2(v, u);
	}
}

void solve()
{
	cin >> n;

	for (int i = 1; i <= n; i++) 
	{
		cin >> weight[i];
		tot += weight[i];
	}

	for (int i = 1; i < n; i++)
	{
		int f, t, v;
		cin >> f >> t >> v;

		tr.add_edge(f, t, v);
		tr.add_edge(t, f, v);
	}

	dfs_1(1, 0);
	dfs_2(1, 0);

	LL minn = (1ll << 60);
	for (int i = 1; i <= n; i++)
	{
		minn = min(minn, dp1[i] + dp2[i]);
	}

	cout << minn << '\n';
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	solve();
}