#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int N = 300010;

int a[N][32];
int cnt[32];

vector<int> divisors(long long n)
{
	vector<int> res;
	for (int i=1;i<=n/i;i++)
	{
		if (n%i==0)
		{
			res.push_back(i);
			if (i!=n/i) res.push_back(n/i);
		}
	}

	sort(res.begin(),res.end());
	return res;
}

void solve()
{
	int n;
	cin >> n;

	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j < 32; j++) a[i][j] = 0;
	}

	for (int i = 0 ; i < 32; i++) cnt[i] = 0;

	for (int i = 1; i <= n; i++)
	{
		int x;
		cin >> x;

		for (int j = 30; j >= 0; j--)
		{
			int v = x >> j & 1;
			a[i][j] = v;
			cnt[j] += v;
		}
	}

	int flag = false;
	int found_bit = false;
	int gcd;
	for (int i = 30; i >= 0; i--)
	{
		if (!cnt[i]) continue;

		flag = true;
		if (!found_bit)
		{
			gcd = cnt[i];
			found_bit = true;
		}
		else
		{
			gcd = __gcd(gcd, cnt[i]);
		}
	}

	if (!flag)
	{
		for (int i = 1; i <= n; i++) cout << i << ' ';
		cout << '\n';
		return;
	}

	vector<int> res;
	res = divisors(gcd);

	for (auto i : res) cout << i << ' ';
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