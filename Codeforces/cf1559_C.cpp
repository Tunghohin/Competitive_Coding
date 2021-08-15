#include <iostream>

using namespace std;

int rd[10010];

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

		for (int i = 1; i <= n; i++)
		{
			cin >> rd[i];
		}

		if (rd[1] == 1)
		{
			cout << n + 1 << ' ';
			for (int i = 1; i < n; i++) cout << i << ' ';
			cout << n << '\n';
		}

		else if (rd[n] == 0)
		{
			for (int i = 1; i <= n; i++) cout << i << ' ';
			cout << n + 1 << '\n';
		}

		else
		{
			int pos = 0;
			for (int i = 1; i < n; i ++)
			{
				if (rd[i] == 0 && rd[i + 1] == 1)
				{
					pos = i;
					break;
				}
			}

			for (int i = 1; i <= pos; i++) cout << i << ' ';
			cout << n + 1 << ' ';
			for (int i = pos + 1; i < n; i++) cout << i << ' ';
			cout << n << '\n';
		}
	}
}