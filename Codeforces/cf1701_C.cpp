#include <iostream>

using namespace std;

int cnt[200010];

bool check(int x, int n)
{
	long long need = 0, can_do = 0;
	for (int i = 1; i <= n; i++)
	{
		if (x >= cnt[i])
		{
			can_do += (x - cnt[i]) / 2;
		}
		else need += cnt[i] - x;
	}

	return need <= can_do;
}

void solve()
{
	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= n; i++) cnt[i] = 0;

	for (int i = 1; i <= m; i++)
	{
		int x;
		cin >> x;
		cnt[x]++;
	}

	int res;
	int l = 0, r = 2 * m + 1;
	while (l <= r)
	{
		int mid = (l + r) / 2;
		if (check(mid, n))
		{
			res = mid;
			r = mid - 1;
		}
		else l = mid + 1;
	}
	cout << res << '\n';
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