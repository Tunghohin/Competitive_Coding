#include <iostream>

using namespace std;

void solve()
{
	long long a, b, c;
	cin >> a >> b >> c;

	cout << a + b + c << ' ' << b + c << ' ' << c << '\n';
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