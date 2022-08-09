#include <iostream>
#include <algorithm>

using namespace std;

int mp[1010][1010];
int min_path[1010][1010];
int max_path[1010][1010];

void solve()
{
	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++) cin >> mp[i][j];
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (i == 1)
			{
				max_path[i][j] = max_path[i][j - 1] + mp[i][j];
				min_path[i][j] = min_path[i][j - 1] + mp[i][j];
			}
			else if (j == 1)
			{
				max_path[i][j] = max_path[i - 1][j] + mp[i][j];
				min_path[i][j] = min_path[i - 1][j] + mp[i][j];
			}
			else
			{
				max_path[i][j] = max(max_path[i - 1][j], max_path[i][j - 1]) + mp[i][j];
				min_path[i][j] = min(min_path[i - 1][j], min_path[i][j - 1]) + mp[i][j];
			}
		}
	}

	if (max_path[n][m] % 2 == 1 || max_path[n][m] < 0 || min_path[n][m] > 0)
	{
		cout << "No\n";
	}
	else cout << "Yes\n";
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

	return 0;
}