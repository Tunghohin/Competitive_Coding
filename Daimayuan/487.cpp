#include <iostream>
#include <algorithm>

using namespace std;

int ex_gcd(int a, int b, int &x, int &y)
{
	if (!b)
	{
		x = 1;
		y = 0;
		return a;
	}
	int d = ex_gcd(b, a % b, x, y);
	int t = x;
	x = -y;
	y = -(t + (a / b) * y);
	return d;
}

void solve()
{
	int a, b;
	cin >> a >> b;
	int x = 0, y = 0;
	int d = ex_gcd(a, b, x, y);
	while (x < 0 || y < 0) x += b / d, y += a / d;
	cout << x << ' ' << y << '\n';
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int T;
	cin >> T;

	while (T--)
	{
		solve();
	}

	return 0;
}