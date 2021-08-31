#include <iostream>
#include <cmath>

using namespace std;

void solve()
{
	int a, b;
	cin >> a >> b;

	if (abs(a - b) % 2) cout << -1 << '\n';
	else if (!a && !b) cout << 0 << '\n';
	else if (a == b) cout << 1 << '\n';
	else cout << 2 << '\n';
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