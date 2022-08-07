#include <iostream>

using namespace std;

int change(int x)
{
	return x + (x % 10);
}

int a[200010];
void solve()
{
	int n;
	cin >> n;

	bool has_five = false;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		if (a[i] % 10 == 5 || a[i] % 10 == 0)
		{
			a[i] = change(a[i]);
			has_five = true;
		}
	}

	if (has_five)
	{
		for (int i = 2; i <= n; i++)
		{
			if (a[i] != a[i - 1])
			{
				cout << "No\n";
				return;
			}
		}
		cout << "Yes\n";
		return;
	}
	else
	{
		bool type_one = false, type_two = false;
		for (int i = 1; i <= n; i++)
		{
			while (a[i] % 10 != 2)
			{
				a[i] = change(a[i]);
			}
			if (a[i] % 20 == 2)
			{
				type_one = true;
			}
			else
			{
				type_two = true;
			}
		}

		if (type_one && type_two) cout << "No\n";
		else cout << "Yes\n";
		return;
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