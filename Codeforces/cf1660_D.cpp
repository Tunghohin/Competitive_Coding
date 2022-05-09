#include <iostream>

using namespace std;

int a[200010];

void solve()
{
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) cin >> a[i];

	int max_res = 0;
	int res_l = n, res_r = 0;
	for (int i = 1; i <= n; i++)
	{
		if (a[i] == 0) continue;
		int l = i, r = i;
		int is_neg = (a[i] < 0);
		for (int j = i + 1; j <= n + 1; j++)
		{
			if (a[j] == 0 || j == n + 1)
			{
				i = j;
				break;
			}
			is_neg ^= (a[j] < 0);
			r++;
		}

		if (!is_neg)
		{
			int cur_res = 0;
			for (int j = l; j <= r; j++)
			{
				if (abs(a[j]) == 2)
				{
					cur_res++;
				}
			}

			if (cur_res > max_res)
			{
				max_res = cur_res;
				res_l = l - 1;
				res_r = n - r;
			}
		}
		else
		{
			int cur_l = l, cur_r = r;
			for (int j = l; j <= r; j++)
			{
				if (a[j] < 0)
				{
					cur_l = j;
					break;
				}
			}
			for (int j = r; j >= l; j--)
			{
				if (a[j] < 0)
				{
					cur_r = j;
					break;
				}
			}

			int cur_res = 0;
			for (int j = cur_l + 1; j <= r; j++)
			{
				if (abs(a[j]) == 2)
				{
					cur_res++;
				}
			}
			if (cur_res > max_res)
			{
				max_res = cur_res;
				res_l = cur_l;
				res_r = n - r;
			}

			cur_res = 0;
			for (int j = cur_r - 1; j >= l; j--)
			{
				if (abs(a[j]) == 2)
				{
					cur_res++;
				}
			}
			if (cur_res > max_res)
			{
				max_res = cur_res;
				res_l = l - 1;
				res_r = n - (cur_r - 1);
			}
		}
	}

	cout << res_l << ' ' << res_r << '\n';
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