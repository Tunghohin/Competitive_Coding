#include <iostream>

using namespace std;

long long a[100010];
int n;
long long k;

bool check(long long x)
{
	long long t = k;
	for (int i = 1; i <= n; i++)
	{
		if (t >= (x - a[i]))
			t -= max(0ll, x - a[i]);
		else return false;
	}

	return true;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	cin >> n >> k;

	for (int i = 1; i <= n; i++) cin >> a[i];

	long long l = 0, r = 2e13;
	while (l < r)
	{
		long long mid = (l + r + 1) >> 1;
		if (check(mid)) l = mid;
		else r = mid - 1;
	}

	cout << l;
}