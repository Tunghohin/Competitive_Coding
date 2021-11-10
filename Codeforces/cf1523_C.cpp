#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cmath>

using namespace std;

void print(vector<int> &v)
{
	for (int i = 0; i < (int)v.size() - 1; i++)
	{
		cout << v[i] << '.';
	}
	cout << v.back() << '\n';
}

void solve()
{
	int n;
	cin >> n;

	vector<int> v;
	for (int i = 1; i <= n; i++)
	{
		int x;
		cin >> x;

		if (x == 1) v.push_back(x);

		else
		{
			while (v.back() != x - 1) v.pop_back();
			v.pop_back();
			v.push_back(x);
		}

		print(v);
	}
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