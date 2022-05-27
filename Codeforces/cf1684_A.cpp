#include <iostream>

using namespace std;

void solve()
{
	string s;
	cin >> s;

	if (s.length() == 2)
	{
		cout << s[1] << '\n';
		return;
	}

	int minn = 9;
	for (int i = 0; i < (int)s.length(); i++)
	{
		minn = min(minn, (s[i] - '0'));
	}

	cout << minn << '\n';
}

int main()
{
	int T;
	cin >> T;

	while (T--)
	{
		solve();
	}
}