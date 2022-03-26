#include <iostream>
#include <cstring>

using namespace std;

const int N = 510;

int s[N];
long long dp[N][N];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	memset(dp, 0x3f, sizeof(dp));

	int n;
	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		int x;
		cin >> x;
		s[i] = s[i - 1] + x;
	}

	for (int i = 1; i <= n; i++) dp[i][i] = 0;

	for (int length = 1; length < n; length++)
	{
		for (int i = 1; i <= n; i++)
		{
			int l = i, r = i + length;
			if (r > n) continue;
			for (int k = l; k < r; k++)
			{
				dp[l][r] = min(dp[l][r], dp[l][k] + dp[k + 1][r] + s[r] - s[l - 1]);
			}
		}
	}

	cout << dp[1][n];
}