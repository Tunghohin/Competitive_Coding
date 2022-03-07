#include <iostream>
#include <map>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	map<pair<int, int>, int> mp;

	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= m; i++)
	{
		int x, y;
		cin >> x >> y;
		mp[{x, y}]++;
	}


}