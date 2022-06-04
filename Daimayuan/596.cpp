#include <iostream>
#include <map>

using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;

	map<pair<int, int>, int> mp;
	bool flag = true;
	for (int i = 1; i <= m; i++)
	{
		int a, b;
		cin >> a >> b;
		if (flag && a == b)
		{
			flag = false;
		}
		if (flag && mp.count({a, b}))
		{
			flag = false;
		}
		mp[{a, b}]++, mp[{b, a}]++;
	}
	flag? cout << "Yes\n" : cout << "No\n";
}