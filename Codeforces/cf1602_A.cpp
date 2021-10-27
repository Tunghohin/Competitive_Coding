#include <iostream>

using namespace std;

void solve()
{
	string s;
	cin >> s;

	int minn = 30, pos = -1;
	for (int i = 0; i < (int)s.length(); i++)
	{
		if (s[i] - 'a' < minn)
		{
			minn = s[i] - 'a';
			pos = i;
		}
	}

	cout << (char)(minn + 'a') << ' ';
	for (int i = 0; i < (int)s.length(); i++)
	{
		if (i != pos) cout << s[i];
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