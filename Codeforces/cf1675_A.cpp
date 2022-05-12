#include <iostream>

using namespace std;

void solve()
{
	int a, b, c, x, y;
	cin >> a >> b >> c >> x >> y;

	int need = 0;
	if (a < x)
	{
		need += x - a;
	}
	if (b < y)
	{
		need += y - b;
	}

	if (need)
	{
		if (need <= c) cout << "YES\n";
		else cout << "NO\n";
		return;
	}

	cout << "YES\n";
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