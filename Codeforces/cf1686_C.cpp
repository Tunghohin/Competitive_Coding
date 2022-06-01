#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int a[100010];

void solve()
{
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) cin >> a[i];

	if (n % 2 == 1)
	{
		cout << "No\n";
		return;
	}

	sort(a + 1, a + 1 + n);
	int p_min = 1, p_max = (1 + n) / 2 + 1;
	vector<int> res;
	while (p_min <= (1 + n) / 2)
	{
		res.push_back(a[p_min]);
		p_min++;
		res.push_back(a[p_max]);
		p_max++;
	}

	for (int i = 1; i < n - 1; i++)
	{
		if ((res[i - 1] < res[i]) != (res[i + 1]) < res[i])
		{
			cout << "No\n";
			return;
		}
		if (res[i] == res[i - 1] || res[i] == res[i + 1])
		{
			cout << "No\n";
			return;
		}
	}

	cout << "Yes\n";
	for (auto i : res)
	{
		cout << i << ' ';
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