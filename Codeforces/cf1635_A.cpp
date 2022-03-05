#include <iostream>

using namespace std;

void solve()
{
	int n;
	cin >> n;

	int res = 0;
	for (int i = 1; i <= n; i++)
	{
		int x;
		cin >> x;
		res |= x;
	}

	cout << res << '\n';
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