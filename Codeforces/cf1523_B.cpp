#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cmath>

using namespace std;

long long arr[1010];

void operation(int x, int y)
{
	cout << 1 << ' ' << x << ' ' << y << '\n';
	cout << 2 << ' ' << x << ' ' << y << '\n';
	cout << 1 << ' ' << x << ' ' << y << '\n';
	cout << 2 << ' ' << x << ' ' << y << '\n';
	cout << 1 << ' ' << x << ' ' << y << '\n';
	cout << 2 << ' ' << x << ' ' << y << '\n';
}

void solve()
{
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) cin >> arr[i];

	cout << n * 3 << '\n';
	for (int i = 1; i <= n; i += 2)
	{
		operation(i, i + 1);
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