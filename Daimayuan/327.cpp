#include <iostream>
#include <cstring>

using namespace std;

const int N = 110;
int n, L, R;

int a[N], dp[N][N][N];
int s[N];

void solve()
{
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		s[i] = s[i - 1] + a[i];
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = i; j <= n; j++)
		{
			for (int k = 1; k <= n; k++)
			{
				dp[i][j][k] = 0x3f3f3f3f;
			}
		}
	}

	for (int length = 0; length < n; length++)
	{
		for (int l = 1; l + length <= n; l++)
		{
			int r = l + length;
			if (length == 0)
			{
				dp[l][r][1] = 0;
			}
			else
			{
				for (int k = 2; k <= n; k++)
				{
					for (int mid = l; mid < r; mid++)
					{
						dp[l][r][k] = min(dp[l][r][k], dp[l][mid][1] + dp[mid + 1][r][k - 1]);
					}
					if (k >= L && k <= R) dp[l][r][1] = min(dp[l][r][1], dp[l][r][k]);
				}
				dp[l][r][1] += s[r] - s[l - 1];
			}
		}
	}

	if (dp[1][n][1] >= 0x3f3f3f3f) cout << 0 << '\n';
	else cout << dp[1][n][1] << '\n';
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	while (cin >> n >> L >> R)
	{
		solve();
	}
}