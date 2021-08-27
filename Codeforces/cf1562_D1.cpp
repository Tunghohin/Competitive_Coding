#include <iostream>
#include <cstring>

using namespace std;
int s_s[300010];

void solve()
{
	int len, m;
	cin >> len >> m;
	string s;
	cin >> s;

	memset(s_s, 0, sizeof(s_s));

	bool pos = true;
	for (int i = 1; i <= len; i++)
	{
		int num;
		if (s[i - 1] == '+') num = 1;
		else num = -1;

		if (pos)
		{
			s_s[i] = s_s[i - 1] + num;
			pos = false;
		}
		else
		{
			s_s[i] = s_s[i - 1] - num;
			pos = true;
		}

	}

	while (m--)
	{
		int l, r;
		cin >> l >> r;
		if ((r - l) % 2 == 0)
		{
			cout << 1 << '\n';
		}
		else
		{
			if (s_s[r] - s_s[l - 1] == 0)
			{
				cout << 0 << '\n';
			}
			else cout << 2 << '\n';
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