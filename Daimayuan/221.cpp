#include <iostream>

using namespace std;

const int N = 510, M = 510;

int w[N][M];
int dp[N][M];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++) cin >> w[i][j];
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j <= m; j++)
		{
			for (int k = 0; k <= j; k++)
			{
				dp[i][j] = max(dp[i][j], dp[i - 1][j - k] + w[i][k]);
			}
		}
	}

	cout << dp[n][m];
}