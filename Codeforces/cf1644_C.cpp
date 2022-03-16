#include <iostream>
#include <vector>

using namespace std;

int a[5010];
int s[5010];
int seg_sum[5010][5010];
int length_max[5010];

void solve()
{
	int n, x;
	cin >> n >> x;

	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		s[i] = s[i - 1] + a[i];
	}

	for (int len = 1; len <= n; len++)
	{
		length_max[len] = -0x3f3f3f3f;
		for (int i = 1; i + len - 1 <= n; i++)
		{
			seg_sum[i][i + len - 1] = s[i + len - 1] - s[i - 1];
			length_max[len] = max(length_max[len], seg_sum[i][i + len - 1]);
		}
	}

	vector<int> res;
	for (int k = 0; k <= n; k++)
	{
		int max_res = 0;
		for (int i = 0; i <= n; i++)
		{
			max_res = max(max_res, length_max[i] + min(k, i) * x);
		}
		res.push_back({max_res});
	}

	for (auto i : res)
	{
		cout << i << ' ';
	}
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