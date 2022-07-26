#include <iostream>

using namespace std;

int num[200010];

void solve()
{
	int n, a, b;
	cin >> n >> a >> b;

	for (int i = 1; i <= n; i++) num[i] = 0;

	if ((abs(a - b) > 1) || a + b + 2 > n)
	{
		cout << -1 << '\n';
		return;
	}

	if (a > b)
	{
		int cur_num = n;
		int cnt = 0;
		for (int i = 2; i <= n; i += 2)
		{
			if (cnt == a) break;
			cnt++;
			num[i] = cur_num--;
		}

		cur_num = n - a;
		for (int i = 1; i <= n; i++)
		{
			if (num[i]) continue;
			num[i] = cur_num--;
		}
	}
	else if (b > a)
	{
		int cur_num = 1;
		int cnt = 0;
		for (int i = 2; i <= n; i += 2)
		{
			if (cnt == b) break;
			cnt++;
			num[i] = cur_num++;
		}

		cur_num = b + 1;
		for (int i = 1; i <= n; i++)
		{
			if (num[i]) continue;
			num[i] = cur_num++;
		}
	}
	else
	{
		int cur_num = n;
		int cnt = 0;
		for (int i = 2; i <= n; i += 2)
		{
			if (cnt == a) break;
			cnt++;
			num[i] = cur_num--;
		}

		cur_num = 1;
		for (int i = 1; i <= n; i++)
		{
			if (num[i]) continue;
			num[i] = cur_num++;
		}
	}

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