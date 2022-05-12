#include <iostream>

using namespace std;

void solve()
{
	string s;
	cin >> s;

	int fst_pos = (int)s.length() - 1;
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == '0')
		{
			fst_pos = i;
			break;
		}
	}

	int cnt = 0;
	for (int i = fst_pos; i >= 0; i--)
	{
		cnt++;
		if (s[i] == '1') break;
	}


	cout << cnt << '\n';
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