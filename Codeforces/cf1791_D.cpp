#include <bits/stdc++.h>

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
	string s;
	cin >> s;

	int cnt_p = 0, cnt_s = 0;
	map<char, int> mp_p, mp_s;
	for (int i = (int)s.length() - 1; i > 0; i--)
	{
		if (mp_s[s[i]] == 0)
		{
			cnt_s++;
		}
		mp_s[s[i]]++;
	}
	mp_p[s[0]]++;
	cnt_p++;

	int res = cnt_p + cnt_s;
	for (int i = 1; i < (int)s.length() - 1; i++)
	{
		if (mp_p[s[i]] == 0)
		{
			cnt_p++;
		}
		if (mp_s[s[i]] == 1)
		{
			cnt_s--;
		}
		mp_p[s[i]]++;
		mp_s[s[i]]--;
		res = max(res, cnt_s + cnt_p);
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