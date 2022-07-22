#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

int a[200010];

void solve()
{
	int n;
	cin >> n;

	map<int, int> mp;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		mp[a[i]]++;
	}

	int od = 0, ev = 0;
	for (auto i : mp)
	{
		if (i.second > 1) ev++;
		else od++;
	}

	cout << ev + (od + 1) / 2 << '\n';
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