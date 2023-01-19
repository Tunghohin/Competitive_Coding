#include <bits/stdc++.h>

using namespace std;
using LL = long long;
using ULL = unsigned long long;
using PII = pair<int, int>;

vector<int> t_cnt(1000010);

void solve()
{
	int n;
	cin >> n;

	int tot = 0;
	for (int i = 1; i <= n; i++)
	{
		ULL x;
		cin >> x;
		int cur_i = i;
		int cur_tot = 0;

		while (x % 2 == 0)
		{
			x /= 2;
			tot++;
		}
		while (cur_i % 2 == 0)
		{
			cur_i /= 2;
			cur_tot++;
		}
		t_cnt[i] = cur_tot;
	}

	if (tot >= n)
	{
		cout << 0 << '\n';
		return;
	}

	int need_op = n - tot;
	sort(t_cnt.begin() + 1, t_cnt.begin() + 1 + n, greater<int>());
	int res = 0;
	for (int i = 1; i <= n; i++)
	{
		need_op -= t_cnt[i];
		res++;
		if (need_op <= 0)
		{
			cout << res << '\n';
			return;
		}
	}
	cout << -1 << '\n';
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