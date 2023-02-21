#include <bits/stdc++.h>

using namespace std;
using LL = long long;
using ULL = unsigned long long;
using PII = pair<int, int>;
using PLI = pair<long long, int>;
using PLL = pair<long long, long long>;

void solve()
{
	LL a, b, c, d;
	cin >> a >> b >> c >> d;

	if (a == 0)
	{
		cout << 1 << '\n';
		return;
	}

	LL safty = max(0ll, a + 2 * min(b, c));
	if (safty == 0)
	{
		cout << 1 << '\n';
		return;
	}

	LL dif = abs(b - c);
	LL res = safty + min(a, dif + d);

	if (dif + d > a)
	{
		cout << res + 1 << '\n';
	}
	else cout << res << '\n';
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