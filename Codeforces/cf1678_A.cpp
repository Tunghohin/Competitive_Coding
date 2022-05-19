#include <iostream>

using namespace std;

int num[110];

void solve()
{
	int n;
	cin >> n;

	for (int i = 0; i <= 100; i++) num[i] = 0;

	int zero_cnt = 0;
	bool has_same = false;
	for (int i = 1; i <= n; i++)
	{
		int x;
		cin >> x;
		if (x == 0)
		{
			zero_cnt++;
		}
		if (num[x]) has_same = true;
		num[x]++;
	}

	if (zero_cnt != 0)
	{
		cout << n - zero_cnt << '\n';
		return;
	}
	if (has_same)
	{
		cout << n << '\n';
		return;
	}
	cout << n + 1 << '\n';
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