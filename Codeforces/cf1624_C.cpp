#include <iostream>
#include <algorithm>

using namespace std;

bool used[110];
int a[110];

void solve()
{
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) used[i] = false;

	for (int i = 1; i <= n; i++) cin >> a[i];

	sort(a + 1, a + 1 + n, greater<int>());

	bool flag = true;
	for (int i = n; i >= 1; i--)
	{
		int x = a[i];
		while (x > n || used[x]) x /= 2;
		if (x > 0) used[x] = true;
		else flag = false;
	}

	flag? cout << "Yes\n" : cout << "No\n";
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