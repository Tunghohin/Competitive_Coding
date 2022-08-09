#include <iostream>

using namespace std;

void solve()
{
	int n;
	cin >> n;
	string s1, s2;
	cin >> s1 >> s2;

	int zz_cnt = 0, zo_cnt = 0, oz_cnt = 0, oo_cnt = 0;
	for (int i = 0; i < n; i++)
	{
		if (s1[i] == '1' && s2[i] == '1') oo_cnt++;
		if (s1[i] == '1' && s2[i] == '0') oz_cnt++;
		if (s1[i] == '0' && s2[i] == '1') zo_cnt++;
		if (s1[i] == '0' && s2[i] == '0') zz_cnt++;
	}

	int res = 0x3f3f3f3f;
	if ((zo_cnt == 0) && (oz_cnt == 0))
	{
		res = 0;
	}
	if (zo_cnt == oz_cnt)
	{
		res = min(res, oz_cnt + oz_cnt);
	}
	if (oo_cnt)
	{
		int cur_oo = zo_cnt + 1;
		int cur_zo = oo_cnt - 1;
		int cur_oz = zz_cnt;
		int cur_zz = oz_cnt;
		if (cur_oz == cur_zo) res = min(res, cur_oz + cur_zo + 1);
	}
	if (oz_cnt)
	{
		int cur_oo = zo_cnt;
		int cur_zo = oo_cnt;
		int cur_oz = zz_cnt + 1;
		int cur_zz = oz_cnt - 1;
		if (cur_oz == cur_zo) res = min(res, cur_oz + cur_zo + 1);
	}

	if (res == 0x3f3f3f3f) cout << -1 << '\n';
	else cout << res << '\n';
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