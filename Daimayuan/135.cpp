#include <iostream>

using namespace std;

const int N = 1010;

int a[N], dp[N];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) cin >> a[i];

	int res = -1;
	for (int i = 1; i <= n; i++)
	{
		dp[i] = 1;
		for (int j = 1; j < i; j++)
		{
			if (a[j] < a[i])
			{
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}

		res = max(res, dp[i]);
	}

	cout << res;
}