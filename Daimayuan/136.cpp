#include <iostream>

using namespace std;

const int N = 1010;

int a[N], b[N];
int dp[N][N];

int main()
{
	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= m; i++) cin >> b[i];

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			if (a[i] == b[j]) dp[i][j] = max(dp[i - 1][j - 1] + 1, dp[i][j]);
		}
	}

	cout << dp[n][m];
}