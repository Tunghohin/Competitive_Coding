#include <iostream>
#include <vector>

using namespace std;

const int N = 2010;

long long dp[N];
int f[N];
long long son_sum[N];
int depth[N];

vector<int> son[N];

struct path
{
	int x, y, v;
};
vector<path> paths[N];

void get_depth(int u)
{
	for (auto i : son[u])
	{
		depth[i] = depth[u] + 1;
		get_depth(i);
	}
}

void dfs(int u)
{
	for (auto to : son[u])
	{
		dfs(to);
		son_sum[u] += dp[to];
	}

	dp[u] = son_sum[u];
	for (auto cur_path : paths[u])
	{
		long long tmp = son_sum[u];
		int cur_x = cur_path.x;
		while (cur_x != u)
		{
			tmp += son_sum[cur_x] - dp[cur_x];
			cur_x = f[cur_x];
		}
		cur_x = cur_path.y;
		while (cur_x != u)
		{
			tmp += son_sum[cur_x] - dp[cur_x];
			cur_x = f[cur_x];
		}
		tmp += cur_path.v;
		dp[u] = max(dp[u], tmp);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int n, m;
	cin >> n >> m;

	for (int i = 2; i <= n; i++)
	{
		cin >> f[i];
		son[f[i]].push_back(i);
	}

	get_depth(1);

	for (int i = 1; i <= m; i++)
	{
		int x, y, v;
		cin >> x >> y >> v;

		int cur_x = x, cur_y = y;
		while (cur_x != cur_y)
		{
			if (depth[cur_x] > depth[cur_y]) cur_x = f[cur_x];
			else cur_y = f[cur_y];
		}

		paths[cur_x].push_back({x, y, v});
	}

	dfs(1);

	cout << dp[1];
}