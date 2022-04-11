#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int N = 100010;

int a[N];
long long tr[N];

int n;

int low_bit(int x)
{
	return x & (-x);
}

int find(int x, vector<int> &v)
{
	return (int)(lower_bound(v.begin(), v.end(), x) - v.begin());
}

void modify(int x, int v)
{
	for (; x <= n; x += low_bit(x))
	{
		tr[x] += v;
	}
}

long long query(int x)
{
	long long res = 0;
	for (; x; x -= low_bit(x))
	{
		res += tr[x];
	}
	return res;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	cin >> n;

	long long inv_cnt = 0;

	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		a[i] = n + 1 - a[i];
	}

	for (int i = 1; i <= n; i++)
	{
		inv_cnt += query(a[i]);
		modify(a[i], 1);
	}

	cout << inv_cnt;
}