#include <iostream>
#include <cstring>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

int a[200010];

bool comp(pair<int, char> A, pair<int, char> B)
{
	if (A.second == B.second) return A.first < B.first;
	return A.second < B.second;
}


void solve()
{
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) cin >> a[i];

	string s;
	cin >> s;

	vector<pair<int, char>> v;
	for (int i = 0; i < n; i++)
	{
		v.push_back({a[i], s[i]});
	}

	sort(v.begin(), v.end(), comp);

	bool flag = true;
	for (int i = 0; i < (int)v.size(); i++)
	{
		if (v[i].first < i + 1 && v[i].second == 'B')
		{
			flag = false;
			break;
		}
		if (v[i].first > i + 1 && v[i].second == 'R')
		{
			flag = false;
			break;
		}
	}

	flag? cout << "YES\n" : cout << "NO\n";
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