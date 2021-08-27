#include <iostream>

using namespace std;

void solve()
{
	int l, r;
	cin >> l >> r;

	if (l > (r / 2) + 1)
	{
		cout << r % l << '\n';
	}
	else
	{
		cout << r % ((r/2) + 1) << '\n';
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