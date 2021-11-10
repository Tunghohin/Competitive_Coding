#include <iostream>
#include <cstring>
#include <cmath>
#include <vector>

using namespace std;

int find(char x, string &s)
{
	for (int i = 0; i < (int)s.length(); i++)
	{
		if (s[i] == x) return i;
	}

	return 0;
}

void solve()
{
	string s;
	cin >> s;

	string p;
	cin >> p;

	int res = 0;
	for (int i = 1; i < p.length(); i++)
	{
		res += abs(find(p[i], s) - find(p[i - 1], s));
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