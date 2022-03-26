#include <iostream>
#include <cstring>

using namespace std;

const int N = 510;

int a[N];
int s[N];
long long dp[N][N];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	memset(dp, 0x3f, sizeof(dp));

	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) cin >> a[i];
	a[0] = a[n];

	for (int i = 1; i <= 2 * n; i++)
	{
		s[i] = s[i - 1] + a[i % n];
	}

	for (int i = 1; i <= 2 * n; i++) dp[i][i] = 0;

	for (int length = 1; length < n; length++)
	{
		for (int i = 1; i <= 2 * n; i++)
		{
			int l = i, r = i + length;
			if (r > 2 * n) continue;
			for (int k = l; k < r; k++)
			{
				dp[l][r] = min(dp[l][r], dp[l][k] + dp[k + 1][r] + s[r] - s[l - 1]);
			}
		}
	}

	long long res = 0x3f3f3f3f3f3f3f3f;
	for (int i = 1; i <= n; i++)
	{
		res = min(dp[i][i + n - 1], res);
	}

	cout << res << '\n';
}