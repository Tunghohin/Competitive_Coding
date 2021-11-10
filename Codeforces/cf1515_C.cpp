#include <iostream>
#include <set>
#include <queue>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cmath>

using namespace std;

int h[200010];

void solve()
{
	int n, m, x;
	cin >> n >> m >> x;

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
	for (int i = 1; i <= m; i++)
	{
		q.push({0, i});
	}

	cout << "YES\n";
	for (int i = 1; i <= n; i++)
	{
		int height;
		cin >> height;

		auto u = q.top();
		q.pop();

		cout << u.second << ' ';
		q.push({u.first + height, u.second});
	}

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