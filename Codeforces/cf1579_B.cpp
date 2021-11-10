#include <iostream>
#include <vector>

using namespace std;

int a[55];

bool check(int n)
{
	for (int i = 1; i < n; i++)
	{
		if (a[i] > a[i + 1]) return false;
	}

	return true;
}

void shift(int l, int r, int d)
{
	int tmp = a[l];
	for (int i = l + 1; i <= r; i++) a[i - 1] = a[i];
	a[r] = tmp;
}

struct movement
{
	int l, r, d;
};

void solve()
{
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) cin >> a[i];
	a[n + 1] = 0x3f3f3f3f;
	int cnt = 0;

	vector<movement> res;

	while (true)
	{
		bool flag = true;
		for (int i = n; i > 1 && flag; i--)
		{
			if (a[i - 1] <= a[i]) continue;
			for (int j = i; j <= n + 1; j++)
			{
				if (a[j] > a[i - 1])
				{
					cnt++;
					shift(i - 1, j - 1, 1);
					res.push_back({i - 1, j - 1, 1});
					flag = false;
					break;
				}
			}
		}

		if (check(n))
		{
			cout << cnt << '\n';
			for (auto i : res)
			{
				cout << i.l << ' ' << i.r << ' ' << i.d << '\n';
			}
			return;
		}
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