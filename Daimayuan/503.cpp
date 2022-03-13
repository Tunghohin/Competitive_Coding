#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

int main()
{
	int n;
	cin >> n;

	long long res = 0;
	vector<pair<int, int>> v;
	for (int i = 1; i <= n; i++)
	{
		int d, p;
		cin >> d >> p;
		v.push_back({d, p});
	}

	sort(v.begin(), v.end());

	while (v.back().first > n)
	{
		res += v.back().second;
		v.pop_back();
	}

	priority_queue<int> q;
	for (int i = n; i >= 1; i--)
	{
		while (v.back().first >= i)
		{
			q.push({v.back().second});
			v.pop_back();
		}

		if (!q.empty())
		{
			res += q.top();
			q.pop();
		}
	}

	cout << res << '\n';
}