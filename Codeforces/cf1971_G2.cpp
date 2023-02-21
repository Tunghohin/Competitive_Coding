#include <bits/stdc++.h>
#define int long long

using namespace std;
using LL = long long;
using ULL = unsigned long long;
using PII = pair<int, int>;
using PLI = pair<long long, int>;
using PLL = pair<long long, long long>;

const int inf = 0x3f3f3f3f;

void solve()
{
	int n, c;
	cin >> n >> c;

	vector<PII> a;
	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		a.push_back({x + min(i + 1, n - i), x + 1 + i});
	}
	sort(a.begin(), a.end());
	vector<LL> prefix;
	prefix.push_back(0);
	for (int i = 0; i < n; i++)
	{
		prefix.push_back(prefix.back() + a[i].first);
	}

	int res = 0;
	for (int i = 0; i < n; i++)
	{
		int cur_c = c - a[i].second;
		int l = 0, r = n;
		int cur_res = 0;
		while (l <= r)
		{
			int mid = (l + r) >> 1;
			int now = mid;
			int cur_cost = prefix[mid];

			if (mid > i)
			{
				cur_cost -= a[i].first;
			}
			else now = now + 1;

			if (cur_cost <= cur_c)
			{
				cur_res = max(cur_res, now);
				l = mid + 1;
			}
			else r = mid - 1;
		}
		res = max(res, cur_res);
	}
	cout << res << '\n';
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;

	while (T--)
	{
		solve();
	}
}