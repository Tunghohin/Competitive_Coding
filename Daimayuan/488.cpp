#include <iostream>
#define int long long

using namespace std;

int ex_gcd(int a, int b, int &x, int &y)
{
	if (b == 0)
	{
		x = 1;
		y = 0;
		return a;
	}
	int d = ex_gcd(b, a % b, x, y);
	int t = x;
	x = y;
	y = t - a / b * y;
	return d;
}

bool solve_linear_equation(int a, int b, int c, int &x, int &y)
{
	int d = ex_gcd(a, b, x, y);
	if (c % d != 0) return false;

	int k = c / d;

	__int128 xx = (__int128)x * k;

	int t = b / d;
	x = (int)(xx % (__int128)t + t) % t;
	y = (c - a * x) / b;
	if (y < 0) return false;

	return true;
}

void solve()
{
	int a, b, d;
	cin >> a >> b >> d;
	int x = 0, y = 0;

	bool statue = solve_linear_equation(a, b, d, x, y);
	if (!statue) cout << "-1\n";
	else cout << x << ' ' << y << '\n';
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
}