#include <iostream>
#include <vector>

using namespace std;

const int N = 100010;

int n, m;

vector<int> son[N];

long long f[N];
long long dp[N];
long long res[N];

void dfs_1(int u)
{
	f[u] = 1;
	for (auto to : son[u])
	{
		dfs_1(to);
		f[u] = f[u] * (f[to] + 1) % m;
	}
}

void dfs_2(int u)
{
	static long long pre[N], suf[N];

	int node_size = (int)son[u].size();

	pre[0] = 1;
	for (int i = 0; i < node_size; i++)
	{
		pre[i + 1] = pre[i] * (f[son[u][i]] + 1) % m;
	}

	suf[node_size] = 1;
	for (int i = node_size - 1; i >= 0; i--)
	{
		suf[i] = suf[i + 1] * (f[son[u][i]] + 1) % m;
	}

	for (int i = 0; i < node_size; i++)
	{
		int to = son[u][i];
		dp[to] = (dp[u] + 1) * pre[i] % m * suf[i + 1] % m;
		res[to] = (dp[to] + 1) * f[to] % m;
	}

	for (auto to : son[u])
	{
		dfs_2(to);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	cin >> n >> m;

	for (int i = 2; i <= n; i++)
	{
		int x;
		cin >> x;
		son[x].push_back(i);
	}

	dfs_1(1);
	dfs_2(1);

	res[1] = f[1];
	for (int i = 1; i <= n; i++) cout << res[i] << '\n';
}