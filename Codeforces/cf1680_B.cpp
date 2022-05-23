#include <iostream>

using namespace std;

char mp[10][10];

void solve()
{
	int n, m;
	cin >> n >> m;

	int fx = 0x3f3f3f3f, fy = 0x3f3f3f3f;
	pair<int, int> fr = {-1, -1};
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			cin >> mp[i][j];
			if (mp[i][j] == 'R')
			{
				if (fr.first == -1)
				{
					fr.first = i, fr.second = j;
				}
				fy = min(fy, j);
			}
		}
	}

	if (fy == fr.second)
	{
		cout << "YES\n";
	}
	else cout << "NO\n";
}

int main()
{
	int T;
	cin >> T;

	while (T--)
	{
		solve();
	}
}