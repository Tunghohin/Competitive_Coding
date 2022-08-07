#include <iostream>

using namespace std;

int a[100];

void solve()
{
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) cin >> a[i];

	if (n % 2 == 1)
	{
		cout << "Mike\n";
		return;
	}
	else
	{
		int min_idx = 1;
		for (int i = 1; i <= n; i++)
		{
			if (a[i] < a[min_idx])
			{
				min_idx = i;
			}
		}
		min_idx % 2 == 1? cout << "Joe\n" : cout << "Mike\n";
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