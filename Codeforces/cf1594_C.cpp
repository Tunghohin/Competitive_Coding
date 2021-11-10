#include <iostream>
#include <vector>
#include <cstring>
#include <cmath>

using namespace std;

void solve()
{
	int n;
	char c;
	string s;
	cin >> n >> c >> s;

	bool ok = true;
	for (int i = 0; i < n; i++)
	{
		if (s[i] != c)
		{
			ok = false;
			break;
		}
	}

	if (ok)
	{
		cout << 0 << '\n';
		return;
	}

	vector<int> res;
	for (int i = 1; i < n + 1; i++)
	{
		ok = true;
		for (int j = i; j < n + 1; j++)
		{
			ok &= (s[j - 1] == c);
			j += i - 1;
		}

		if (ok)
		{
			res.push_back(i);
			break;
		}
	}

	if (!ok)
	{
		res.push_back(n);
		res.push_back(n - 1);
	}

	cout << res.size() << '\n';
	for (auto i : res) cout << i << ' ';
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