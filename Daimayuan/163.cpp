#include <iostream>

using namespace std;

const int N = 110;

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
		for (int k = 1; k <= limit[i]; k++)
		{
			for (int j = m; j >= cost[i]; j--)
			{
				dp[j] = max(dp[j], dp[j - cost[i]] + val[i]);
			}
		}
	}

	cout << dp[m];
}