#include <iostream>
#include <cstring>

using namespace std;

const int N = 19;

int path[N][N], dp[1 << 18][N];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int n;
	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++) cin >> path[i][j];
	}

	memset(dp, 0x3f, sizeof(dp));
	dp[1][1] = 0;
	for (int i = 1; i < (1 << n); i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (dp[i][j] == 0x3f3f3f3f) continue;
			for (int k = 1; k <= n; k++)
			{
				if ((i & (1 << (k - 1))) == 0)
				{
					dp[i + (1 << (k - 1))][k] = min(dp[i + (1 << (k - 1))][k], dp[i][j] + path[j][k]);
				}
			}
		}
	}

	int res = 0x3f3f3f3f;
	for (int i = 2; i <= n; i++)
	{
		res = min(res, dp[(1 << n) - 1][i] + path[i][1]);
	}

	cout << res << '\n';
}