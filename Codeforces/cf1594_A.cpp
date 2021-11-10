#include <iostream>
#include <vector>
#include <cstring>
#include <cmath>

using namespace std;

void solve()
{
	long long n;
	cin >> n;

	if (n % 2 == 0)
	{
		cout << -n + 1 << ' ' << n << '\n';
		return;
	}

	else
	{
		cout << n / 2 << ' ' << n / 2 + 1 << '\n';
		return;
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