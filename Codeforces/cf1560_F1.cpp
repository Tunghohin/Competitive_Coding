#include <iostream>

using namespace std;

string solve1(string n)
{
	string res(n.length(), '9');
	for (char c = '8'; c >= '0'; c--)
	{
		string t(n.length(), c);
		if (t >= n)
			res = t;
	}

	return res;
}

string solve2(string n)
{
	string res = solve1(n);

	for (char a = '0'; a <= '9'; a++)
		for (char b = a + 1; b <= '9'; b++)
		{
			bool n_ok = true;
			for (int i = 0; i < n.length(); i++)
			{
				if (n[i] < b)
				{
					string t = n;
					if (t[i] < a) t[i] = a;
					else t[i] = b;
					for (int j = i + 1; j < n.length(); j++)
						t[j] = a;
					if (res > t)
						res = t;
				}

				if (n[i] != a && n[i] != b)
				{
					n_ok = false;
					break;
				}
			}

			if (n_ok) return n;
		}

	return res;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int T;
	cin >> T;

	while (T--)
	{
		string s;
		int k;

		cin >> s >> k;

		if (k == 1) cout << solve1(s) << '\n';
		else cout << solve2(s) << '\n';
	}
}