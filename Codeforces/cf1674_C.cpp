#include <iostream>
#include <algorithm>

using namespace std;

void solve()
{
	string s, t;
	cin >> s >> t;

	if (t.length() == 1 && t[0] == 'a')
	{
		cout << 1 << '\n';
		return;
	}

	else
	{
		for (int i = 0; i < (int)t.length(); i++)
		{
			if (t[i] == 'a')
			{
				cout << -1 << '\n';
				return;
			}
		}
	}

	long long res = 1;
	for (int i = 1; i <= s.length(); i++)
	{
		res *= 2;
	}

	cout << res << '\n';
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