#include <bits/stdc++.h>
#define int long long

using namespace std;
using LL = long long;
using ULL = unsigned long long;
using PII = pair<int, int>;
using PLI = pair<long long, int>;
using PLL = pair<long long, long long>;

void solve()
{
	int n;
	cin >> n;

	int res = 1;
	vector<LL> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];

	auto check = [&](int x) {
		int cnt = 0;
		for (int i = 0; i < n; i++)
		{
			LL u = llround(sqrtl(a[i] + x));
			if (u * u == a[i] + x)
			{
				cnt++;
			}
		}
		res = max(res, cnt);
	};

	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			LL dif = a[j] - a[i];
			for (int k = 1; k * k <= dif; k++)
			{
				if (dif % k || (dif / k - k) % 2) continue;
				LL p = ((dif / k) - k) / 2;
				if (p * p < a[i]) continue;

				check(p * p - a[i]);
			}
		}
	}

	cout << res << '\n';
}

signed main()
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