#include <iostream>

using namespace std;

int mp[2][100010];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int T;
	cin >> T;

	while (T--)
	{
		int n;
		cin >> n;

		for (int i = 0; i <= 1; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				cin >> mp[i][j];
			}
		}

		int ans = 0x3f3f3f3f;
		int pre1 = 0, pre2 = 0;
		for (int i = 1; i <= n; i++) pre1 += mp[0][i];
		for (int i = 1; i <= n; i++)
		{
			pre1 -= mp[0][i];
			ans = min(ans, max(pre1, pre2));
			pre2 += mp[1][i];
		}

		cout << ans << '\n';
	}
}