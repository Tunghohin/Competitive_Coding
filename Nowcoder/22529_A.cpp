#include <bits/stdc++.h>

using namespace std;
using LL = long long;
using ULL = unsigned long long;
using PII = pair<int, int>;
using PLI = pair<long long, int>;
using PLL = pair<long long, long long>;

LL num[4] = {2, 5, 11, 13};

void solve()
{
	LL n;
	cin >> n;

	LL res = 0;
	for (int i = 0; i < (1 << 4); i++)
	{
		LL set_size = n;
		for (int j = 0; j < 4; j++)
		{
			if ((i >> j) & 1)
			{
				set_size /= num[j];
			}
		}
		if (__builtin_popcount(i) % 2)
		{
			res -= set_size;
		}
		else res += set_size;
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