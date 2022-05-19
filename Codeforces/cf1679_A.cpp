#include <iostream>

using namespace std;

void solve()
{
	long long x;
	cin >> x;

	if (x == 4 || x == 6)
	{
		cout << 1 << ' ' << 1 << '\n';
		return;
	}

	if (x % 2 == 1 || x < 7)
	{
		cout << -1 << '\n';
		return;
	}

	cout << (x / 6) + (((x / 2) % 3) != 0) << ' ';
	cout << x / 4 << '\n';
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