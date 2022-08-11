#include <iostream>

using namespace std;

void solve()
{
	int n;
	cin >> n;

	if (n == 1)
	{
		cout << 1 << '\n';
		return;
	}

	else
	{
		cout << n << ' ';
		for (int i = 1; i < n; i++) cout << i << ' ';
	}
	cout << '\n';
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