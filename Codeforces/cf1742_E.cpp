#include <bits/stdc++.h>

using namespace std;
using LL = long long;
using PII = pair<int, int>;

int a[200010];
int prefix_max[200010];
long long prefix_sum[200010];

void solve()
{
	int n, q;
	cin >> n >> q;

	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		prefix_max[i] = max(prefix_max[i - 1], a[i]);
		prefix_sum[i] = prefix_sum[i - 1] + a[i];
	}

	for (int i = 1; i <= q; i++)
	{
		int k;
		cin >> k;
		int l = 0, r = n;
		while (l < r)
		{
			int mid = (l + r + 1) >> 1;
			if (prefix_max[mid] <= k) l = mid;
			else r = mid - 1;
		}

		cout << prefix_sum[l] << ' ';
	}
	cout << '\n';
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