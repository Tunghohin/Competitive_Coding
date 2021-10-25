#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <algorithm>
#define int long long

using namespace std;

void solve()
{
	int a, b, c;
	cin >> a >> b >> c;
	cout << (a + b * 2 + c * 3) % 2 << '\n';
}

signed main()
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