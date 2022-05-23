#include <iostream>

using namespace std;

void solve()
{
	int l1, r1, l2, r2;
	cin >> l1 >> r1 >> l2 >> r2;

	if (l1 <= l2 && l2 <= r1)
	{
		cout << l2 << '\n';
	}
	else if (l2 <= l1 && l1 <= r2)
	{
		cout << l1 << '\n';
	}
	else
	{
		cout << l1 + l2 << '\n';
	}
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