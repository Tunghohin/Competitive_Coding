#include <iostream>
#include <map>
#include <vector>

using namespace std;

void solve()
{
	int n;
	vector<string> v;
	map<string, int> mp;
	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		string s;
		cin >> s;
		mp[s] = 1;
		v.push_back(s);
	}

	for (auto const &s : v)
	{
		bool flag = false;
		for (int len = 1; len <= s.length() - 1; len++)
		{
			flag |= (mp[s.substr(0, len)] && mp[s.substr(len, s.length() - len)]);
		}
		cout << flag;
	}
	cout << '\n';
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