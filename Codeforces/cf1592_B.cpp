#include <iostream>
#include <algorithm>

using namespace std;

int a[200010];
int b[200010];

void solve()
{
	int n, x;
	cin >> n >> x;

	for (int i = 1; i <= n; i++) cin >> a[i];

	for (int i = 1; i <= n; i++) b[i] = a[i];
	sort(b + 1, b + 1 + n);

	bool flag = true;
	for (int i = n - x + 1; i <= x; i++)
	{
		flag &= (a[i] == b[i]);
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