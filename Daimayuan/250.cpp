#include <iostream>
#include <cstring>

using namespace std;

const int N = 30;

int val[N];
int dp[1 << 20];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) cin >> val[i];

	memset(dp, 0x3f, sizeof(dp));
	dp[0] = 0;

	for (int i = 0; i < (1 << n); i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (!(i & (1 << (j - 1))))
			{
				dp[i + (1 << (j - 1))] = min(dp[i + (1 << (j - 1))], dp[i] + val[j]);

				for (int k = j + 1; k <= n; k++)
				{
					if (!(i & (1 << (k - 1))))
					{
						dp[i + (1 << (j - 1)) + (1 << (k - 1))] =
							min(dp[i + (1 << (j - 1)) + (1 << (k - 1))], dp[i] + (val[j] ^ val[k]));
					}
				}
				break;
			}
		}
	}

	cout << dp[(1 << n) - 1];
}