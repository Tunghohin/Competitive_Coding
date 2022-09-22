#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int N = 200010;

int n;
int dp[N];

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
		return (x % 2 == 1)? x + 1 : x - 1;
	}

	void add_edge(int from, int to)
	{
		e[++tot] = {to, head[from], 0}; head[from] = tot;
		e[++tot] = {from, head[to], 1}; head[to] = tot;
	}

	void dfs_1(int u, int from)
	{
		for (int i = head[u]; i; i = e[i].next)
		{
			int v = e[i].to;
			if (v == from) continue;
			dfs_1(v, u);

			dp[u] += dp[v] + e[i].val;
		}
	}

	void dfs_2(int u, int from_edge)
	{
		if (u != 1)
		{
			dp[u] = dp[e[inv_edge(from_edge)].to] - e[from_edge].val + e[inv_edge(from_edge)].val;
		}

		for (int i = head[u]; i; i = e[i].next)
		{
			int v = e[i].to;
			if (i == inv_edge(from_edge)) continue;

			dfs_2(v, i);
		}
	}
};

Tree<long long> tr;
void solve()
{
	cin >> n;

	for (int i = 1; i < n; i++)
	{
		int u, v;
		cin >> u >> v;

		tr.add_edge(u, v);
	}

	tr.dfs_1(1, 0);
	tr.dfs_2(1, 0);

	int min_res = 0x3f3f3f3f;
	vector<int> node_res;
	for (int i = 1; i <= n; i++)
	{
		if (dp[i] < min_res)
		{
			min_res = dp[i];
			node_res.clear();
			node_res.push_back(i);
		}
		else if (dp[i] == min_res) node_res.push_back(i);
	}

	cout << min_res << '\n';
	for (auto u : node_res) cout << u << ' ';
	cout << '\n';
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	solve();
}