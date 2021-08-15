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
		int n;
		string s;
		cin >> n;
		cin >> s;

		int st = -1;
		bool flag = false;
		for (int i = 0; i < n; i++)
		{
			if (s[i] == '?')
			{
				if (!flag)
				{
					flag = true;
					st = i - 1;
				}
				else continue;
			}
			else
			{
				if (flag)
				{
					flag = false;
					for (int j = i - 1; j > st && j >=0; j--)
					{
						if (s[j + 1] == 'R') s[j] = 'B';
						else s[j] = 'R';
					}
				}
				else continue;
			}
		}

		if (s[n - 1] == '?')
		{
			for (int i = n - 1; s[i] == '?'; i--)
			{
				st = i;
			}

			for (int i = st; i < n; i++)
			{
				if (s[i - 1] == 'R')
				{
					s[i] = 'B';
				}
				else s[i] = 'R';
			}
		}

		cout << s << '\n';
	}

	return 0;
}