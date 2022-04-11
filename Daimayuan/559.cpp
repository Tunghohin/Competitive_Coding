#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long LL;

const int N = 200010;

int n;
int val[N];
LL res[N];

struct Node
{
	int id, xs, val;
};

vector<Node> q[N];

int find(int x, vector<int> &v)
{
	return (int)(lower_bound(v.begin(), v.end(), x) - v.begin());
}

namespace BIT
{
	LL tr[N];
	int low_bit(int x)
	{
		return x & (-x);
	}
	void modify(int x, LL v)
	{
		for (; x <= n; x += low_bit(x))
		{
			tr[x] += v;
		}
	}
	LL query(int x)
	{
		LL res = 0;
		for (; x; x -= low_bit(x))
		{
			res += tr[x];
		}
		return res;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	cin >> n;

	vector<int> v;
	for (int i = 1; i <= n; i++)
	{
		cin >> val[i];
		v.push_back(val[i]);
	}

	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());
	for (int i = 1; i <= n; i++)
	{
		val[i] = find(val[i], v) + 1;
	}

	for (int k = 1; k <= n - 1; k++)
	{
		for (int i = 1; k * (i - 1) + 2 <= n; i++)
		{
			int L = k * (i - 1) + 2, R = min(n, k * i + 1);
			q[L - 1].push_back({k, -1, val[i]});
			q[R].push_back({k, 1, val[i]});
		}
	}


	for (int i = 1; i <= n; i++)
	{
		BIT::modify(val[i], 1);

		for (auto u : q[i])
		{
			res[u.id] += u.xs * BIT::query(u.val - 1);
		}
	}

	for (int i = 1; i <= (n - 1); i++) cout << res[i] << ' ';
}