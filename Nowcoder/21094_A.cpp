#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;
using LL = long long;

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

void solve()
{
	int x, y, m, n, l;
	cin >> x >> y >> m >> n >> l;
	int u = 0, v = 0;
	int d = ex_gcd(n - m, l, u, v);
	if ((x - y) % d != 0)
	{
		cout << "Impossible\n";
		return;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	solve();
}