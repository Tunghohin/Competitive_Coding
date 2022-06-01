#include <iostream>

using namespace std;

int a[100010];
long long dp[100010];

void solve()
{
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		dp[i] = 0;
	}

	for (int i = 2; i <= n; i++)
	{
		dp[i] = dp[i - 1];
		if (a[i] < a[i - 1])
		{
			dp[i] = max(dp[i], dp[i - 2] + 1);
		}
	}

	cout << dp[n] << '\n';
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int T;
	cin >> T;

	while (T--)
	{
		solve();
	}
}