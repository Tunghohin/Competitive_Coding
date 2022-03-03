#include <iostream>
#include <stack>
#include <vector>
#include <unordered_map>

using namespace std;

pair<int, int> arr[1000010];
int suffix_max[1000010];
unordered_map<int, int> mp;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int n, q;
	cin >> n >> q;

	for (int i = 1; i <= n; i++)
	{
		int x;
		cin >> x;
		arr[i] = {x, 0};
	}

	vector<pair<int, int>> query;
	for (int i = 1; i <= q; i++)
	{
		int op;
		cin >> op;

		if (op == 1)
		{
			int x, y;
			cin >> x >> y;

			arr[x] = {y, i};
			mp[i] = -1;
		}
		else
		{
			int y;
			cin >> y;
			mp[i] = y;
		}
	}

	for (int i = q; i >= 1; i--)
	{
		suffix_max[i] = max(suffix_max[i + 1], mp[i]);
	}

	for (int i = 1; i <= n; i++)
	{
		arr[i].first = max(suffix_max[arr[i].second + 1], arr[i].first);
	}

	for (int i = 1; i <= n; i++)
	{
		cout << arr[i].first << ' ';
	}
}