#include <iostream>

using namespace std;

const int N = 2010;

int cost[N], val[N], limit[N];
int dp[N];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= n; i++)
	{
		cin >> cost[i] >> val[i] >> limit[i];
	}

	for (int i = 1; i <= n; i++)
	{
		int res = limit[i];
		for (int k = 1; k <= res; res -= k, k *= 2)
		{
			for (int j = m; j >= cost[i] * k; j--)
			{
				dp[j] = max(dp[j], dp[j - cost[i] * k] + val[i] * k);
			}
		}
		for (int j = m; j >= cost[i] * res; j--)
		{
			dp[j] = max(dp[j], dp[j - cost[i] * res] + val[i] * res);
		}
	}

	cout << dp[m];
}