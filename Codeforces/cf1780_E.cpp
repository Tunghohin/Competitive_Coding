#include <bits/stdc++.h>

using namespace std;
using LL = long long;
using ULL = unsigned long long;
using PII = pair<int, int>;
using PLI = pair<long long, int>;
using PLL = pair<long long, long long>;

void solve()
{
	int x;
	cin >> x;

	if (x % 2)
	{
		cout << -1 << '\n';
		return;
	}

	int tmp = x >> 1;

	int res_a = 0, res_b = 0;
	for (int i = 0; i <= 30; i++)
	{
		int bit_xor = (x >> i) & 1;
		int bit_and = (tmp >> i) & 1;

		if (bit_and)
		{
			if (bit_xor)
			{
				cout << -1 << '\n';
				return;
			}
			else
			{
				res_a += (1 << i);
				res_b += (1 << i);
			}
		}
		else
		{
			if (bit_xor)
			{
				res_a += (1 << i);
			}
			else continue;
		}
	}

	cout << res_a << ' ' << res_b << '\n';
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