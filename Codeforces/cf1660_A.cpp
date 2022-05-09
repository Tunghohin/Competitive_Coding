#include <iostream>

using namespace std;

void solve()
{
	long long a, b;
	cin >> a >> b;

	if (a == 0)
	{
		cout << 1 << '\n';
		return;
	}

	cout << 2 * b + a + 1 << '\n';
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