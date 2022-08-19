#include <iostream>
#include <iomanip>

using namespace std;

void solve()
{
	int x, k;
	cin >> k >> x;

	if (k >= 2 * x)
	{
		cout << fixed << setprecision(4) << 0.0;
	}
	else if (k > x)
	{
		cout << fixed << setprecision(4) << (double)((2.0 * x - k) * (2.0 * x - k)) / (double)(x * x * 2.0);
	}
	else if (k == x)
	{
		cout << fixed << setprecision(4) << 0.5;
	}
	else
	{
		cout << fixed << setprecision(4) << (double)(x * x - k * k) / (double)(x * x * 2.0);
	}

	cout << '\n';
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