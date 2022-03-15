#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct Node
{
	int x, w, idx;
};

bool comp_weight(Node a, Node b)
{
	return a.w < b.w;
}

bool comp_x(Node a, Node b)
{
	return a.x < b.x;
}

void solve()
{
	int n, m;
	cin >> n >> m;

	vector<Node> v;
	for (int i = 1; i <= m; i++)
	{
		int x, w;
		cin >> x >> w;
		v.push_back({x, w, i});
	}

	sort(v.begin(), v.end(), comp_weight);
	sort(v.begin(), v.begin() + (2 * n), comp_x);

	long long sum = 0;
	vector<pair<int, int>> res;
	for (int i = 0, j = 2 * n - 1; i < j; i++, j--)
	{
		sum += v[i].w + v[j].w;
		res.push_back({v[i].idx, v[j].idx});
	}

	cout << sum << '\n';
	for (auto i : res)
	{
		cout << i.first << ' ' << i.second << '\n';
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