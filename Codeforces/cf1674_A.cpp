#include <iostream>

using namespace std;

void solve()
{
	int x, y;
	cin >> x >> y;

	if (x > y || y % x != 0)
	{
		cout << 0 << ' ' << 0 << '\n';
		return;
	}

	cout << 1 << ' ' << y / x << '\n';
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