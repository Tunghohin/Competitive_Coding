#include <iostream>

using namespace std;

void solve()
{
	int l, r, a;
	cin >> l >> r >> a;

	int res1 = (r / a) + (r % a);
	int res2 = (r / a) - 1 + (a - 1);

	if ((r / a - 1) * a + (a - 1) < l) res2 = res1;

	cout << max(res1, res2) << '\n';
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