#include <iostream>

using namespace std;

int num[110];

void solve()
{
	int n;
	cin >> n;
	string s;
	cin >> s;

	int seg_cnt = 1;
	int need_change = 0;
	int cur = -1;
	for (int i = 0; i < n; i += 2)
	{
		if (s[i] == s[i + 1])
		{
			if (cur == -1)
			{
				cur = s[i] - '0';
			}
			if ((s[i] - '0') != cur)
			{
				seg_cnt++;
				cur = s[i] - '0';
			}
		}
		else
		{
			need_change++;
		}
	}

	cout << need_change <<  '\n';
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