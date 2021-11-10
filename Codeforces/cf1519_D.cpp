#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cmath>

using namespace std;

long long a[5010];
long long b[5010];
long long prefix_sum[5010];

void solve()
{
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++) cin >> b[i];

	for (int i = 1; i <= n; i++)
	{
		prefix_sum[i] = prefix_sum[i - 1] + (a[i] * b[i]);
	}

	long long res = prefix_sum[n];
	for (int i = 1; i <= n; i++)
	{
		long long cur = a[i] * b[i];

		for (int l = i - 1, r = i + 1; l >= 1 && r <= n; l--, r++)
		{
			cur += a[l] * b[r];
			cur += a[r] * b[l];

			long long now = cur + prefix_sum[l - 1] + (prefix_sum[n] - prefix_sum[r]);
			res = max(res, now);
		}

		cur = 0;
		for (int l = i, r = i + 1; l >= 1 && r <= n; l--, r++)
		{
			cur += a[l] * b[r];
			cur += a[r] * b[l];

			long long now = cur + prefix_sum[l - 1] + (prefix_sum[n] - prefix_sum[r]);
			res = max(res, now);
		}
	}

	cout << res << '\n';
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int T;
	T = 1;

	while (T--)
	{
		solve();
	}
}