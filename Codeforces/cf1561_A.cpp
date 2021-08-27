#include <iostream>

using namespace std;

int a[1000];

bool check(int *q, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		if (q[i] > q[i + 1]) return true;
	}
	return false;
}

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

		for (int i = 0; i < n; i++) cin >> a[i];

		bool odev = true; //true odd
		int cnt = 0;
		while (check(a, n))
		{
			if (odev)
			{
				cnt++;
				for (int i = 0; i < n - 2; i += 2)
				{
					if (a[i] > a[i + 1]) swap(a[i], a[i + 1]);
				}
				odev = false;
			}
			else
			{
				cnt++;
				for (int i = 1; i < n - 1; i += 2)
				{
					if (a[i] > a[i + 1]) swap(a[i], a[i + 1]);
				}
				odev = true;
			}
		}

		cout << cnt << '\n';
	}
}