#include <iostream>
#include <cstring>

using namespace std;

const int N = 510;

int a[N];
long long dp[N][N];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) cin >> a[i];

	memset(dp, 0x3f, sizeof(dp));
	for (int i = 1; i < n; i++) dp[i][i + 1] = 0;

	for (int length = 2; length < n; length++)
	{
		for (int i = 1; i <= n; i++)
		{
			int l = i, r = i + length;
			if (r > n) continue;
			for (int k = i + 1; k <= r - 1; k++)
			{
				dp[l][r] = min(dp[l][r], dp[l][k] + dp[k][r] + a[k] * a[l] * a[r]);
			}
		}
	}

	cout << dp[1][n];
}