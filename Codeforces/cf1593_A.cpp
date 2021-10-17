#include <iostream>

using namespace std;

void solve()
{
	long long a, b, c;
	cin >> a >> b >> c;

	long long x = max(b, c) - a + 1;
	long long y = max(a, c) - b + 1;
	long long z = max(a, b) - c + 1;

	if (a > b && a > c) x = 0;
	else if (b > c && b > a) y = 0;
	else if (c > a && c > b) z = 0;

	cout << x << ' ' << y << ' ' << z << '\n';
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