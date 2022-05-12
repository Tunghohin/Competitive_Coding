#include <iostream>
#include <cstring>

using namespace std;

void solve()
{
	int n, k;
	cin >> n >> k;
	string s;
	cin >> s;

	if (k >= 26)
	{
		for (int i = 0; i < n; i++)
		{
			cout << 'a';
		}
		cout << '\n';
		return;
	}

	char mx_char = 'a';
	for (int i = 0; i < n; i++)
	{
		if (s[i] <= mx_char) continue;
		if (s[i] - 'a' > k)
		{
			k -= mx_char - 'a';
			int to = s[i] - k;
			for (char c = s[i]; c > to; c--)
			{
				for (char &cc : s)
				{
					if (cc == c) cc = char(c - 1);
				}
			}
			break;
		}
		else mx_char = max(mx_char, s[i]);
	}

	for (char &c : s)
	{
		if (c <= mx_char) c = 'a';
	}

	cout << s << '\n';
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