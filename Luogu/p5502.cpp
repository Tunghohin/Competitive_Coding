#include <iostream>
#include <algorithm>

using namespace std;

long long a[100010];

long long max_gcd(int l, int r)
{
	if (l == r) return a[l];

	long long res = 0, tmp;

	int mid = (l + r) >> 1;

	int L = mid, R = mid;
	tmp = a[mid];
	while (L > l && R <= r)
	{
		tmp = __gcd(tmp, a[--L]);
		while (R < r && !(a[R + 1] % tmp)) R++;
		while (L > l && !(a[L - 1] % tmp)) L--;

		res = max(res, (R - L + 1) * tmp);
	}

	L = mid, R = mid;
	tmp = a[mid];
	while (R < r && L >= l)
	{
		tmp = __gcd(tmp, a[++R]);
		while (L > l && !(a[L - 1] % tmp)) L--;
		while (R < r && !(a[R + 1] % tmp)) R++;

		res = max(res, (R - L + 1) * tmp);
	}

	return max(res, max(max_gcd(l, mid), max_gcd(mid + 1, r)));
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) cin >> a[i];

	cout << max_gcd(1, n) << '\n';

	return 0;
}
