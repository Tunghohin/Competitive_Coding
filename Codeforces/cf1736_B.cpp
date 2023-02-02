#include <bits/stdc++.h>

using namespace std;
using LL = long long;
using ULL = unsigned long long;
using PII = pair<int, int>;
using PLI = pair<long long, int>;
using PLL = pair<long long, long long>;

map<int, int> pf;

int __lcm(int a, int b)
{
	int g = __gcd(a, b);
	return a / g * b;
}

void solve()
{
	pf.clear();

	int n;
	cin >> n;

	vector<int> a(n + 10, 1);
	for (int i = 1; i <= n; i++) cin >> a[i];

	vector<int> b(n + 10);
	for (int i = 1; i <= n + 1; i++)
	{
		b[i] = __lcm(a[i], a[i - 1]);
	}

	for (int i = 1; i <= n; i++)
	{
		if (__gcd(b[i], b[i + 1]) != a[i])
		{
			cout << "No\n";
			return;
		}
	}
	cout << "Yes\n";
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