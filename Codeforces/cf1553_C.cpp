#include <iostream>

using namespace std;

int solve(string &s)
{
	int fst_chance = 5;
	int sec_chance = 5;
	int fst = 0;
	int sec = 0;
	int end = 10;

	for (int i = 0; i < 10; i++)
	{
		if (i % 2)
		{
			sec_chance--;
			if (s[i] == '1')
			{
				sec++;
			}
		}
		else
		{
			fst_chance--;
			if (s[i] == '1')
			{
				fst++;
			}
		}
		if (fst > sec)
		{
			if (sec_chance < abs(fst - sec))
			{
				end = i + 1;
				break;
			}
		}
		else
		{
			if (fst_chance < abs(fst - sec))
			{
				end = i + 1;
				break;
			}
		}
	}

	return end;
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
		cin >> s;

		string fst, sec;
		fst = s;
		sec = s;

		for (int i = 0; i < 10; i++)
		{
			if (s[i] == '?')
			{
				if (i % 2)
				{
					sec[i] = '1';
					fst[i] = '0';
				}
				else
				{
					sec[i] = '0';
					fst[i] = '1';
				}
			}
		}

		int fst_end = solve(fst);
		int sec_end = solve(sec);

		cout << min(fst_end, sec_end) << '\n';
	}
}