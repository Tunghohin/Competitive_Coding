#include <iostream>
#include <algorithm>

using namespace std;

double a[200010];

void solve()
{
	int n;
	cin >> n;

	double sum = 0;
	for (int i = 1; i <= n; i++) cin >> a[i], sum += a[i];

	double k = sum / n;
	k *= 2;

	sort(a + 1, a + 1 + n);

	long long res = 0;
	for (int i = 1; i <= n; i++)
	{
		int left = 0, right = 0;

		int l = i, r = n;
		while (l < r)
		{
			int mid = (l + r) >> 1;
			if (a[mid] < k - a[i]) l = mid + 1;
			else r = mid;
		}
		if (a[i] + a[l] == k) left = l;

		l = i, r = n;
		while (l < r)
		{
			int mid = (l + r + 1) >> 1;
			if (a[mid] > k - a[i]) r = mid - 1;
			else l = mid;
		}
		if (a[i] + a[l] == k) right = l;

		int dif = 0;
		if (left) dif = right - left + 1;
		if (left == i) dif--;

		res += dif;
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