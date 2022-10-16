#include <bits/stdc++.h>

using namespace std;
using LL = long long;
using PII = pair<int, int>;

void solve()
{
	map<int, int> mp;

	bool flag = true;

	int n;
	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		int x;
		cin >> x;
		if (mp.count(x)) flag = false;
		mp[x]++;
	}

	flag? cout << "Yes\n" : cout << "No\n";
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