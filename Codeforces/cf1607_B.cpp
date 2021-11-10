#include <iostream>
#include <cstring>
#include <cmath>
#include <vector>

using namespace std;

void solve()
{
	long long x, n;
	cin >> x >> n;

	if (n == 0)
	{
		cout << x << '\n';
		return;
	}

	if (x % 2 == 0)
	{
		long long t = n % 4;
		if (t == 0)
		{
			cout << x << '\n';
			return;
		}
		else
		{
			if (t == 1)
			{
				cout << x - (n - t + 1) << '\n';
				return;
			}
			else if (t == 2)
			{
				cout << x - (n - t + 1) + (n - t + 2) << '\n';
				return;
			}
			else
			{
				cout << x - (n - t + 1) + (n - t + 2) + n << '\n';
				return;
			}
		}
	}

	else
	{
		long long t = n % 4;
		if (t == 0)
		{
			cout << x << '\n';
			return;
		}
		else
		{
			if (t == 1)
			{
				cout << x + (n - t + 1) << '\n';
				return;
			}
			else if (t == 2)
			{
				cout << x + (n - t + 1) - (n - t + 2) << '\n';
				return;
			}
			else
			{
				cout << x + (n - t + 1) - (n - t + 2) - n << '\n';
				return;
			}
		}
	}
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