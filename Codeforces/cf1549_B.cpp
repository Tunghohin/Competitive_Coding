#include <iostream>
#include <vector>

using namespace std;

void solve()
{
	int n;
	cin >> n;
	string a, b;
	cin >> a >> b;

	int cnt = 0;
	for (int i = 0; i < n; i++)
	{
		if (b[i] == '1')
		{
			if (a[i] == '0')
			{
				cnt++;
				a[i] = '2';
			}
			else if (i >= 1 && a[i - 1] == '1')
			{
				cnt++;
				a[i - 1] = '2';
			}
			else if (i < n - 1 && a[i + 1] == '1')
			{
				cnt++;
				a[i + 1] = '2';
			}
			else continue;
		}
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