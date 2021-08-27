#include <iostream>

using namespace std;

void solve()
{
	int len;
	string s;
	cin >> len >> s;
	bool flag = true;
	for (int i = 0; i < len; i++)
	{
		if (((s[i] - '0') % 2 == 0 && s[i] - '0' != 2) || s[i] - '0' == 1 || s[i] - '0' == 9)
		{
			cout << 1 << '\n';
			cout << s[i] - '0' << '\n';
			flag = false;
			break;
		}
	}

	for (int i = 0; i < len - 1 && flag; i++)
	{
		if (s[i] - '0' == 2 && flag)
		{
			for (int j = i + 1; j < len; j++)
			{
				if (s[j] - '0' == 2 || s[j] - '0' == 5 || s[j] - '0' == 7)
				{
					cout << 2 << '\n';
					cout << s[i] - '0' << s[j] - '0' << '\n';
					flag = false;
					break;
				}
			}
		}
		if (s[i] - '0' == 3 && flag)
		{
			for (int j = i + 1; j < len; j++)
			{
				if (s[j] - '0' == 5 || s[j] - '0' == 2 || s[j] - '0' == 3)
				{
					cout << 2 << '\n';
					cout << s[i] - '0' << s[j] - '0' << '\n';
					flag = false;
					break;
				}
			}
		}
		else if (s[i] - '0' == 5 && flag)
		{
			for (int j = i + 1; j < len; j++)
			{
				if (s[j] - '0' == 5 || s[j] - '0' == 2 ||  s[j] - '0' == 7)
				{
					cout << 2 << '\n';
					cout << s[i] - '0' << s[j] - '0' << '\n';
					flag = false;
					break;
				}
			}
		}
		else if (s[i] - '0' == 7 && flag)
		{
			for (int j = i + 1; j < len; j++)
			{
				if (s[j] - '0' == 7 || s[j] - '0' == 2 || s[j] - '0' == 5)
				{
					cout << 2 << '\n';
					cout << s[i] - '0' << s[j] - '0' << '\n';
					flag = false;
					break;
				}
			}
		}
	}
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