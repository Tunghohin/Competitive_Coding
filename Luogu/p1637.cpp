#include <iostream>
#include <cstring>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;

const int N = 30010;

int L_lower[N], R_greater[N];
int tr[N];

int low_bit(int x)
{
	return x & -x;
}

void add(int x, int k)
{
	while (x <= N)
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

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int n;
	cin >> n;

	vector<int> nums;
	vector<int> hash;
	map<long long, int> hashed;
	for (int i = 1; i <= n; i++)
	{
		int x;
		cin >> x;
		nums.push_back(x);
		hash.push_back(x);
	}

	sort(hash.begin(), hash.end());
	int tot = 0;
	for (auto i : hash)
	{
		if (!hashed.count(i))
		{
			hashed[i] = ++tot;
		}
	}

	for (int i = 0; i < (int)nums.size(); i++)
	{
		int tmp = hashed[nums[i]];
		L_lower[i] = get(tmp - 1);
		add(tmp, 1);
	}

	memset(tr, 0, sizeof(tr));
	for (int i = (int)nums.size() - 1; i >= 0; i--)
	{
		int tmp = hashed[nums[i]];
		R_greater[i] = n - i - 1 - get(tmp);
		add(tmp, 1);
	}

	long long res = 0;
	for (int i = 0; i < n; i++)
	{
		res += L_lower[i] * R_greater[i];
	}

	cout << res << '\n';
}