#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

const int N = 100010;

vector<int> son[N];

int dp[N][2];

void dfs(int u)
{
	dp[u][0] = 0, dp[u][1] = 1;
	for (auto to : son[u])
	{
		dfs(to);
		dp[u][1] += min(dp[to][0], dp[to][1]);
		dp[u][0] += dp[to][1];
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int n;
	cin >> n;

	for (int i = 2; i <= n; i++)
	{
		int x;
		cin >> x;
		son[x].push_back(i);
	}

	dfs(1);

	cout << min(dp[1][1], dp[1][0]);
}