#include <iostream>
#include <cstring>

using namespace std;

int dp[1 << 8];
int tmp[1 << 8];
bool enable[1 << 8];
int val[100010];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= n; i++) cin >> val[i];

	for (int i = 0; i < (1 << m); i++)
	{
		if (__builtin_popcount(i) <= (m / 2)) enable[i] = true;
	}

	memset(dp, -0x3f, sizeof(dp));
	dp[0] = 0;
	for (int i = 1; i <= n; i++)
	{
		memset(tmp, -0x3f, sizeof(tmp));
		for (int j = 0; j < (1 << m); j++)
		{
			if (dp[j] >= 0)
			{
				tmp[j >> 1] = max(tmp[j >> 1], dp[j]);
				if (enable[(j >> 1) + (1 << (m - 1))])
				{
					tmp[(j >> 1) + (1 << (m - 1))] =
						max(tmp[(j >> 1) + (1 << (m - 1))], dp[j] + val[i]);
				}
			}
		}
		for (int j = 0; j < (1 << m); j++) dp[j] = tmp[j];
	}

	int res = -0x3f3f3f3f;
	for (int i = 0; i < (1 << m); i++)
	{
		res = max(res, dp[i]);
	}

	cout << res;
}