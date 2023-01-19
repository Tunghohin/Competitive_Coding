#include <bits/stdc++.h>

using namespace std;
using LL = long long;
using PII = pair<int, int>;

int a[110];

void solve()
{
	map<int, char> mp;

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) cin >> a[i];

	string s;
	cin >> s;
	for (int i = 0; i < n; i++)
	{
		if (!mp.count(a[i])) mp[a[i]] = s[i];
		else if (s[i] != mp[a[i]])
		{
			cout << "No\n";
			return;
		}
	}
	cout << "Yes\n";
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