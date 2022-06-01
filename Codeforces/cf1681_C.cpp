#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void solve()
{
	int n;
	cin >> n;

	vector<int> a(110), b(110);
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int j = 1; j <= n; j++) cin >> b[j];

	vector<pair<int, int>> mv;
	for (int i = n; i > 1; i--)
	{
		for (int j = 1; j < i; j++)
		{
			if (a[j] > a[j + 1])
			{
				swap(a[j], a[j + 1]);
				swap(b[j], b[j + 1]);
				mv.emplace_back(j, j + 1);
			}
			if (a[j] == a[j + 1] && b[j] > b[j + 1])
			{
				swap(a[j], a[j + 1]);
				swap(b[j], b[j + 1]);
				mv.emplace_back(j, j + 1);
			}
		}
	}

	for (int i = 1; i < n; i++)
	{
		if (a[i] > a[i + 1] || b[i] > b[i + 1])
		{
			cout << -1 << '\n';
			return;
		}
	}

	cout << mv.size() << '\n';
	for (auto i : mv)
	{
		cout << i.first << ' ' << i.second << '\n';
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