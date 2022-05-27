#include <iostream>

using namespace std;

void solve()
{
	int n;
	cin >> n;
	string s;
	cin >> s;

	int cnt = 0;
	for (int i = (n - 1) / 2; i >= 0; i--)
	{
		if (s[i] == s[(n - 1) / 2]) cnt++;
		else break;
	}
	cout << 2 * cnt - (n & 1) << '\n';
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