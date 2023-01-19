#include <bits/stdc++.h>

using namespace std;
using LL = long long;
using PII = pair<int, int>;

void solve()
{
	int n, q;
	cin >> n >> q;

	LL sum = 0;
	LL od_cnt = 0, ev_cnt = 0;
	for (int i = 1; i <= n; i++)
	{
		LL x;
		cin >> x;
		sum += x;
		if (x % 2 == 0) ev_cnt++;
		else od_cnt++;
	}

	for (int i = 1; i <= q; i++)
	{
		int op;
		LL num;
		cin >> op >> num;
		if (op == 0)
		{
			sum += ev_cnt * num;
			if (num % 2 == 1)
			{
				od_cnt += ev_cnt;
				ev_cnt = 0;
			}
		}
		else
		{
			sum += od_cnt * num;
			if (num % 2 == 1)
			{
				ev_cnt += od_cnt;
				od_cnt = 0;
			}
		}

		cout << sum << '\n';
	}
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