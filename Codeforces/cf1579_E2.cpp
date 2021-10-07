#include <iostream>
#include <cstring>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int tr[400010];

int low_bit(int x)
{
	return x & -x;
}

void add(int x, int k, int n)
{
	while (x <= n)
	{
		tr[x] += k;
		x += low_bit(x);
	}
}

int get(int x)
{
	int res = 0;
	while (x >= 1)
	{
		res += tr[x];
		x -= low_bit(x);
	}

	return res;
}

void solve()
{
	memset(tr, 0, sizeof(tr));
	vector<int> query;
	vector<int> hash;
	map<int, int> hashed;


	long long res = 0;

	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;

		query.push_back(x);
		hash.push_back(x);
	}

	sort(hash.begin(), hash.end());
	int cnt = 0;
	for (auto i : hash)
	{
		if (!hashed.count(i))
		{
			hashed[i] = ++cnt;
		}
	}

	for (int i = 0; i < n; i++)
	{
		int x = hashed[query[i]];
		int lower = get(x - 1), greater = i - get(x);

		res += min(lower, greater);

		add(x, 1, cnt);
	}

	cout << res << '\n';
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int T;
	cin >> T;

	while(T--)
	{
		solve();
	}
}