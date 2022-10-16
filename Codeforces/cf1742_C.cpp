#include <bits/stdc++.h>

using namespace std;
using LL = long long;
using PII = pair<int, int>;

char mp[10][10];

void solve()
{
	for (int i = 1; i <= 8; i++)
	{
		for (int j = 1; j <= 8; j++) cin >> mp[i][j];
	}
	
	char lst = 'R';
	for (int i = 1; i <= 8; i++)
	{
		bool same = true;
		for (int j = 2; j <= 8; j++)
		{
			same &= (mp[i][j] == mp[i][j - 1]);
		}
		if (same && mp[i][1] != 'R') lst = 'R';
	}

	for (int j = 1; j <= 8; j++)
	{
		bool same = true;
		for (int i = 2; i <= 8; i++)
		{
			same &= (mp[i - 1][j] == mp[i][j]);
		}
		if (same && mp[1][j] == 'B') lst = 'B';
	}

	for (int i = 1; i <= 8; i++)
	{
		for (int j = 1; j <= 8; j++) cout << mp[i][j];
		cout << '\n';
	}

	cout << lst << '\n';
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