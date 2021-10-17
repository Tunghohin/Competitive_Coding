#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

long long a[100];

void solve()
{
	int n;
	cin >> n;

	long long minn = 1000010;

	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		minn = min(minn, a[i]);
	}

	vector<long long> v;
	for (int i = 1; i <= n; i++)
	{
		a[i] -= minn;
		if (a[i]) v.push_back(a[i]);
	}

	if (v.empty())
	{
		cout << -1 << '\n';
		return;
	}

	else if (v.size() == 1)
	{
		cout << v[0] << '\n';
		return;
	}

	long long res = v[0];
	for (int i = 1; i < v.size(); i++)
	{
		res = __gcd(res, v[i]);
	}

	cout << res << '\n';
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	vector<string> get25;

	int T;
	cin >> T;

	while (T--)
	{
		solve();
	}
}