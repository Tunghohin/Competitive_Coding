#include <iostream>
#include <algorithm>

using namespace std;

int num[200010];
void solve()
{
	int n, l, r;
	cin >> n >> l >> r;

	for (int i = 1; i <= n; i++)
	{
		num[i] = ((l - 1) / i + 1) * i;
		if (num[i] > r)
		{
			cout << "No\n";
			return;
		}
	}

	cout << "Yes\n";
	for (int i = 1; i <= n; i++) cout << num[i] << ' ';
	cout << '\n';
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