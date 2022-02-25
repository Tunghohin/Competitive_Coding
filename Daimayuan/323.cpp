#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <unordered_map>

using namespace std;

int a[1010];
int dp[1010];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int n;
	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}

	sort(a + 1, a + 1 + n);

	int res = -0x3f3f3f3f;
	for (int i = 1; i <= n; i++)
	{
		dp[i] = 1;
		for (int j = 1; j < i; j++)
		{
			if (max(a[i], a[j]) % min(a[i], a[j]) == 0)
			{
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
		res = max(res, dp[i]);
	}

	cout << res;
}