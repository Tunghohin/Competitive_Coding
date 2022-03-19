#include <iostream>
#include <unordered_map>

using namespace std;

long long a[50];

bool check(int n, long long k)
{
	unordered_map<long long, int> mp;
	for (int i = 1; i <= n; i++) mp[(a[i] + k) % k]++;
	for (auto i : mp) if (i.second >= n / 2) return true;
	return false;
}

void solve()
{
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) cin >> a[i];

	bool flag = true;
	int res = 0;
	for (int k = 1; k <= 20000; k++)
	{
		if (!check(n, k)) flag = false;
		else res = max(res, k);
	}

	if (flag) cout << -1 << '\n';
	else cout << res << '\n';
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