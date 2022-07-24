#include <iostream>
#include <algorithm>

using namespace std;

int a[200010];
void solve()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];

	sort(a + 1, a + 1 + n);

	bool has_one = false;
	bool has_cont = false;
	for (int i = n; i >= 1; i--)
	{
		if (a[i] == 1) has_one = true;
		if (i > 1 && a[i - 1] + 1 == a[i]) has_cont = true;
	}

	if (has_one && has_cont) cout << "No\n";
	else cout << "Yes\n";
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