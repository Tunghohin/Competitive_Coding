#include <iostream>
#include <vector>

using namespace std;

void solve()
{
	int len;
	string s;
	cin >> len >> s;

	vector<char> res;

	for (int i = 0; i <= len; i++)
	{
		if (s[i] == 'L' || s[i] == 'R') res.push_back(s[i]);

		else if (s[i] == 'U') res.push_back('D');

		else if (s[i] == 'D') res.push_back('U');
	}

	for (auto i: res) cout << i;
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