#include <iostream>

using namespace std;

void solve()
{
	string s;
	cin >> s;
	char c;
	cin >> c;

	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == c && (i % 2) == 0)
		{
			cout << "YES\n";
			return;
		}
	}

	cout << "NO\n";
	return;
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