#include <iostream>

using namespace std;

void solve()
{
	int x;
	cin >> x;

	cout << 2 << ' ' << x - 1 << '\n';
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