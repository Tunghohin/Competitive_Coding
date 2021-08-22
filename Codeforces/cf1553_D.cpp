#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int T;
	cin >> T;

	while (T--)
	{
		string s, t;
		cin >> s >> t;

		if (s.length() < t.length())
		{
			cout << "NO\n";
			continue;
		}

		int i = (int)s.length() - 1;
		int j = (int)t.length() - 1;

		int matched = 0;

		while (j >= 0 && i >= 0)
		{
			if (s[i] == t[j])
			{
				i--;
				j--;
				matched++;
			}
			else
			{
				i -= 2;
			}
		}

		matched == (int)t.length()? cout << "Yes\n" : cout << "No\n";
	}

}