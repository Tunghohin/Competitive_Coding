#include <iostream>

using namespace std;

void solve()
{
	int n;
	string s;

	cin >> n >> s;

	bool flag = false;
	for (int i = 0; i < n; i++)
	{
		if (s[i] == '0')
		{
			flag = true;

			if (i >= n / 2)
			{
				cout << 1 << ' ' << i + 1 << ' ' << 1 << ' ' << i << '\n';
			}

			else
			{
				cout << i + 2 << ' ' << n << ' ' << i + 1 << ' ' << n << '\n';
			}

			break;
		}
	}

	if (!flag)
	{
		cout << 1 << ' ' << n - 1 << ' ' << 2 << ' ' << n << '\n';
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int T;
	cin >> T;

	for (int i = 1; i <= T; i++)
	{
		solve();
	}
}