#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> G1[10];
vector<int> G2[10];

bool check(int n, vector<int> &v)
{
	for (int i = 1; i <= n; i++)
	{
		vector<int> tmp1;
		for (auto u : G1[i])
		{
			tmp1.push_back(v[u]);
		}
		vector<int> tmp2;
		for (auto u : G2[v[i]])
		{
			tmp2.push_back(u);
		}
		if (tmp1.size() != tmp2.size()) return false;

		sort(tmp1.begin(), tmp1.end());
		sort(tmp2.begin(), tmp2.end());

		for (int j = 0; j < tmp1.size(); j++)
		{
			if (tmp1[j] != tmp2[j]) return false;
		}
	}
	return true;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= m; i++)
	{
		int a, b;
		cin >> a >> b;
		G1[a].push_back(b);
		G1[b].push_back(a);
	}
	for (int i = 1; i <= m; i++)
	{
		int a, b;
		cin >> a >> b;
		G2[a].push_back(b);
		G2[b].push_back(a);
	}

	vector<int> v;
	v.push_back(0);
	for (int i = 1; i <= n; i++) v.push_back(i);

	bool flag = check(n, v);
	if (!flag)
	{
		while (next_permutation(v.begin() + 1, v.end()))
		{
			if (check(n, v))
			{
				flag = true;
				break;
			}
		}
	}

	flag? cout << "Yes\n" : cout << "No\n";
}
