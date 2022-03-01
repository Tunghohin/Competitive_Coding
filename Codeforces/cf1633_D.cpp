#include <iostream>

using namespace std;

int b[1010];
int b_cnt[1010];

int c[1010];
int dp[1000010];

void solve()
{
	int n, k;
	cin >> n >> k;

	for (int i = 1; i <= n; i++) cin >> b[i];
	for (int i = 1; i <= n; i++) cin >> c[i];
	for (int i = 0; i <= k; i++) dp[i] = 0;

	for (int i = 1; i <= n; i++)
	{
		for (int j = k; j >= b_cnt[b[i]]; j--)
		{
			dp[j] = max(dp[j], dp[j - b_cnt[b[i]]] + c[i]);
		}
	}

	cout << dp[k] << '\n';
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	for (int i = 2; i <= 1000; i++) b_cnt[i] = 1001;
	for (int i = 1; i <= 1000; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			int k = i + (i / j);
			if (k < 1001) b_cnt[k] = min(b_cnt[k], b_cnt[i] + 1);
		}
	}

	int T;
	cin >> T;

	while (T--)
	{
		solve();
	}
}