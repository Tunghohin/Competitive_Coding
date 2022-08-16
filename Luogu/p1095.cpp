#include <iostream>

using namespace std;

long long dp[500010];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int M, S, T;
	cin >> M >> S >> T;

	for (int i = 1; i <= T; i++)
	{
		if (M >= 10)
		{
			dp[i] = dp[i - 1] + 60;
			M -= 10;
		}
		else
		{
			dp[i] = dp[i - 1];
			M += 4;
		}
	}

	for (int i = 1; i <= T; i++)
	{
		if (dp[i] < dp[i - 1] + 17) dp[i] = dp[i - 1] + 17;
		if (dp[i] >= S)
		{
			cout << "Yes\n" << i << '\n';
			return 0;
		}
	}
	cout << "No\n" << dp[T] << '\n';
}