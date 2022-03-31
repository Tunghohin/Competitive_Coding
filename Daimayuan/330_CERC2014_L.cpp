#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int N = 310;

int a[N], b[N], d[N];
int dp[2 * N][2 * N];

void solve()
{
	int n;
	cin >> n;

	vector<int> v;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i] >> b[i] >> d[i];
		v.push_back(a[i]);
		v.push_back(b[i]);
	}

	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());
	int m = (int)v.size();

	for (int i = 1; i <= n; i++)
	{
		a[i] = (int)(lower_bound(v.begin(), v.end(), a[i]) - v.begin()) + 1;
		b[i] = (int)(lower_bound(v.begin(), v.end(), b[i]) - v.begin()) + 1;
	}

	for (int i = 1; i <= m; i++)
	{
		for (int j = 1; j <= m; j++) dp[i][j] = 0x3f3f3f3f;
	}

	for (int length = 0; length < m; length++)
	{
		for (int l = 1; l + length <= m; l++)
		{
			int r = l + length;
			int mxd = -1, mxpos = -1;
			for (int i = 1; i <= n; i++)
			{
				if (a[i] >= l && b[i] <= r)
				{
					if (d[i] > mxd)
					{
						mxd = d[i];
						mxpos = i;
					}
				}
			}

			if (mxd == -1)
			{
				dp[l][r] = 0;
				continue;
			}

			for (int i = a[mxpos]; i <= b[mxpos]; i++)
			{
				dp[l][r] = min(dp[l][r], dp[l][i - 1] + dp[i + 1][r]);
			}
			dp[l][r] += mxd;
		}
	}

	cout << dp[1][m] << '\n';
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int T;
	cin >> T;

	while (T--)
	{
		solve();
	}
}