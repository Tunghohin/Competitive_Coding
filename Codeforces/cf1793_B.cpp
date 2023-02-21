#include <bits/stdc++.h>

using namespace std;
using LL = long long;
using ULL = unsigned long long;
using PII = pair<int, int>;
using PLI = pair<long long, int>;
using PLL = pair<long long, long long>;

void solve()
{
	LL x, y;
	cin >> x >> y;
	LL cur_num = x;
	LL length = abs(x - y);

	cout << 2 * length << '\n';
	while (cur_num >= y)
	{
		cout << cur_num << ' ';
		cur_num--;
	}
	cur_num++;
	while (cur_num < x - 1)
	{
		cur_num++;
		cout << cur_num << ' ';
	}
	cout << '\n';
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