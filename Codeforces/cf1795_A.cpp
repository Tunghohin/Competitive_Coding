#include <bits/stdc++.h>

using namespace std;
using LL = long long;
using ULL = unsigned long long;
using PII = pair<int, int>;
using PLI = pair<long long, int>;
using PLL = pair<long long, long long>;

void solve()
{
	int n, m;
	cin >> n >> m;
	string a, b;
	cin >> a >> b;
	reverse(b.begin(), b.end());
	a += b;

	int same = 0;
	for (int i = 1; i < n + m; i++)
	{
		if (a[i - 1] == a[i]) same++;
	}

	same >= 2? cout << "No\n" : cout << "Yes\n";
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