#include <bits/stdc++.h>

using namespace std;
using LL = long long;
using ULL = unsigned long long;
using PII = pair<int, int>;
using PLI = pair<long long, int>;
using PLL = pair<long long, long long>;

constexpr int N = 200010;

int a[N];

void solve()
{
	int n;
	cin >> n;
	deque<int> dq;

	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		dq.push_back(a[i]);
	}

	sort(dq.begin(), dq.end());

	int l = 1, r = n;
	while (l <= r)
	{
		if (l == r)
		{
			cout << -1 << '\n';
			return;
		}
		bool flag = false;
		if (!dq.empty() && (a[l] == dq.front() || a[l] == dq.back()))
		{
			flag = true;
			//cout << "!\n";
			a[l] == dq.front()? dq.pop_front() : dq.pop_back();
			l++;
		}
		//cout << dq.back() << '\n';
		if (!dq.empty() && (a[r] == dq.front() || a[r] == dq.back()))
		{
			flag = true;
			//cout << "!!\n";
			a[r] == dq.front()? dq.pop_front() : dq.pop_back();
			r--;
		}
		if (!flag) break;
	}

	if (l < r)
	{
		cout << l << ' ' << r << '\n';
	}
	else cout << -1 << '\n';
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