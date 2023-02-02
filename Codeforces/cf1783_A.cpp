#include <bits/stdc++.h>

using namespace std;

void solve()
{	
	int n;
	cin >> n;
	vector<int> v(n + 1);
	for (int i = 0; i < n; i++) cin >> v[i];

	auto comp = [](int& a, int& b)->bool {return a >= b;};
	sort(v.begin(), v.begin() + n, comp);

	bool flag = true;
	for (int i = 0; i < n - 1; i++)
	{
		if (v[i] == v[i + 1]) continue;
		else
		{
			flag = false;
			break;
		}
	}
	if (flag)
	{
		cout << "No\n";
	}
	else
	{
		cout << "Yes\n";
		if (v[0] == v[1])
		{
			for (int i = 2; i < n; i++)
			{
				if (v[i] != v[1]) swap(v[i], v[1]);
			}
		}
		for (int i = 0; i < n; i++) cout << v[i] << ' ';
		cout << '\n';
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;

	while (T--)
	{
		solve();
	}
}