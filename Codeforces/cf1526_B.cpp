#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cmath>

using namespace std;

void solve()
{
	long long n;
	cin >> n;

	for (int i = 0; i < 11; i++)
	{
		if (n % 11 == 0)
		{
			cout << "YES\n";
			return;
		}

		n -= 111;
		if (n < 0) break;
	}

	cout << "NO\n";
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