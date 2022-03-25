#include <iostream>

using namespace std;

const int N = 1010;

int cost[N], val[N];
int dp[N];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= n; i++)
	{
		cin >> cost[i] >> val[i];
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j <= m; j++)
		{
			if (j >= cost[i]) dp[j] = max(dp[j], dp[j - cost[i]] + val[i]);
		}
	}

	cout << dp[m];
}