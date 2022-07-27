#include <iostream>
#include <algorithm>

using namespace std;

int a[100010];
long long C[100010][3];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) cin >> a[i];

	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j < min(i, 3); j++)
		{
			if (j == 0) C[i][j] = 1;
			else C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
		}
	}

	sort(a + 1, a + 1 + n);

	long long res = 0;
	if (a[1] <= a[2] && a[2] < a[3])
	{
		int cnt = 0;
		for (int i = 4; a[i] == a[i - 1]; i++)
		{
			cnt = i;
		}

		cout << cnt - 2 << '\n';
		return 0;
	}
	if (a[1] < a[2] && a[2] == a[3])
	{
		int cnt = 0;
		for (int i = 4; a[i] == a[i - 1]; i++)
		{
			cnt = i;
		}
		cout << C[cnt - 1][2] << '\n';
		return 0;
	}
	if (a[1] == a[2] && a[2] == a[3])
	{
		int cnt = 0;
		for (int i = 4; a[i] == a[i - 1]; i++)
		{
			cnt = i;
		}
		cout << C[cnt][3] << '\n';

		return 0;
	}
}