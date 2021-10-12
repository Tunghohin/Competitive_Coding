#include <iostream>
#include <cstring>

using namespace std;

int mp[1010][6];
int s[1010];

void solve()
{
	int n;
	cin >> n;

	memset(s, 0, sizeof(s));
	memset(mp, 0, sizeof(mp));

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= 5; j++)
		{
			cin >> mp[i][j];
			s[j] += mp[i][j];
		}
	}

	bool flag = false;
	for (int i = 1; i < 5 && !flag; i++)
	{
		for (int j = i + 1; j <= 5 && !flag; j++)
		{
			flag = true;
			for (int k = 1; k <= n; k++)
			{
				if (mp[k][i] == 0 && mp[k][j] == 0)
				{
					flag = false;
					break;
				}
			}
			if (s[j] < n / 2 || s[i] < n / 2) flag = false;
		}
	}

	if (!flag) cout << "NO\n";
	else cout << "YES\n";
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