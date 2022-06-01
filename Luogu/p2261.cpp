#include <iostream>

using namespace std;

typedef long long ll;

void solve()
{
	ll n, k;
	cin >> n >> k;

	ll res = n * k;
	for (ll l = 1; l <= n; l++)
	{
		ll d = k / l;
		ll r;
		if (k / l != 0) r = min(k / d, n);
		else r = n;

		res -= (k / l) * (r - l + 1) * (r + l) / 2;

		l = r;
	}

	cout << res;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	solve();
}