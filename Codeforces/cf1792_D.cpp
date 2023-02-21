#include <bits/stdc++.h>

using namespace std;
using LL = long long;
using ULL = unsigned long long;
using PII = pair<int, int>;
using PLI = pair<long long, int>;
using PLL = pair<long long, long long>;

constexpr int N = 200010;

int a[N];

void solve()
{
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) cin >> a[i];

	sort(a + 1, a + 1 + n);
	
	int cnt = 0;
	map<int, int> mp;
	for (int i = 1; i <= n; i++)
	{
		if (mp[a[i] - 1])
		{
			mp[a[i] - 1]--;
			mp[a[i]]++;
		}
		else
		{
			mp[a[i]]++;
			cnt++;
		}
	}

	cout << cnt << '\n';
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