#include <bits/stdc++.h>
#define int long long

using namespace std;
using LL = long long;
using ULL = unsigned long long;
using PII = pair<int, int>;
using PLI = pair<long long, int>;
using PLL = pair<long long, long long>;

int num[110];

void solve()
{
	int L, R, k;
	cin >> L >> R >> k;

	for (int i = 0; i < k; i++) cin >> num[i];

	int res_R = 0, res_Lm1 = 0;
	for (int i = 0; i < (1 << k); i++)
	{
		int cnt = 0;
		int cur_R = R, cur_Lm1 = L - 1;
		for (int j = 0; j < k; j++)
		{
			if ((i >> j) & 1)
			{
				cur_R /= num[j];
				cur_Lm1 /= num[j];
				cnt++;
			}
		}
		if (cnt % 2)
		{
			res_R -= cur_R;
			res_Lm1 -= cur_Lm1;
		}
		else
		{
			res_R += cur_R;
			res_Lm1 += cur_Lm1;
		}
	}

	cout << res_R - res_Lm1;
}

signed main()
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