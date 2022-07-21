#include <iostream>
#include <algorithm>

using namespace std;

void solve()
{
	int n;
	string s, t;
	cin >> n >> s >> t;

	if (std::count(s.begin(), s.end(), 'b') != std::count(t.begin(), t.end(), 'b'))
	{
		cout << "No\n";
		return;
	}

	for (int i = 0, j = 0; i < s.length(); i++)
	{
		if (s[i] == 'b') continue;
		while (t[j] == 'b') j++;
		if (s[i] != t[j])
		{
			cout << "No\n";
			return;
		}
		else if ((s[i] == 'a' && i > j) || (s[i] == 'c' && i < j))
		{
			cout << "No\n";
			return;
		}
		j++;
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