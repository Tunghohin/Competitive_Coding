#include <iostream>
#include <bitset>

using namespace std;
using LL = long long;

void solve()
{
	LL n, x;
	cin >> n >> x;
	bitset<64> bn(n), bx(x);

	LL l = n, r = (1ll << 62);
	for (LL i = 0; i <= 63; i++)
	{
		if (!bn[i] && !bx[i]) continue;
		if (!bn[i] && bx[i])
		{
			cout << -1 << '\n';
			return;
		}
		if (bn[i] && !bx[i])
		{
			l = max(l, ((n >> i) + 1) << i);
		}
		else
		{
			r = min(r, (((n >> i) + 1) << i) - 1);
		}
	}
	l <= r? cout << l << '\n' : cout << -1 << '\n';
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