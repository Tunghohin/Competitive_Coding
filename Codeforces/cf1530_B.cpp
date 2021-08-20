#include <iostream>

using namespace std;

int table[100][100];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int T;
	cin >> T;

	while (T--)
	{
		int r, c;
		cin >> r >> c;
		for (int i = 0; i <= r + 1; i++)
		{
			for (int j = 0; j <= c + 1; j++) table[i][j] = 0;
		}

		for (int i = 1; i <= c; i++)
		{
			if (table[1][i + 1] == 0 && table[1][i - 1] == 0)
			{
				table[1][i] = 1;
			}
			else continue;
		}

		for (int i = 1; i <= r; i++)
		{
			if (!table[i - 1][c] && !table[i][c - 1] && !table[i - 1][c - 1])
			{
				table[i][c] = 1;
			}
		}

		for (int i = c; i >= 1; i--)
		{
			if (!table[r][i + 1] && !table[r - 1][i] && !table[r - 1][i + 1])
			{
				table[r][i] = 1;
			}
		}

		for (int i = r; i >= 1; i--)
		{
			if (!table[i + 1][1] && ! table[i - 1][1] && !table[i][2] && !table[i + 1][2] && !table[i - 1][2])
			{
				table[i][1] = 1;
			}
		}


		for (int i = 1; i <= r; i++)
		{
			for (int j = 1; j <= c; j++)
			{
				cout << table[i][j];
			}
			cout << '\n';
		}

		cout << '\n';
	}
}