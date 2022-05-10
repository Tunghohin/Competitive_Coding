#include <iostream>

using namespace std;

void solve()
{
	string s;
	cin >> s;

	int res = 0;
	res += (s[0] - 'a') * 25;
	if (s[1] < s[0])
	{
		res += (s[1] - 'a') + 1;
	}
	else
	{
		res += (s[1] - 'a');
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