#include <iostream>
#include <algorithm>
#define int long long

using namespace std;

int a[200010];

void solve()
{
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) cin >> a[i];

	sort(a + 1, a + 1 + n);

	int b_cnt = 1, b_sum = a[1];
	int r_cnt = 1, r_sum = a[n];

	int pl = 1, pr = n;
	while (pl < pr)
	{
		while (b_cnt <= r_cnt && pl < pr)
		{
			b_cnt++;
			b_sum += a[++pl];
		}

		while (r_sum <= b_sum && pl < pr)
		{
			r_cnt++;
			r_sum += a[--pr];
		}

		if (r_sum > b_sum && r_cnt < b_cnt)
		{
			cout << "YES\n";
			return;
		}
	}

	cout << "NO\n";
}

signed main()
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