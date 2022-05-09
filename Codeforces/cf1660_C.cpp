#include <iostream>
#include <cstring>

using namespace std;

bool pre[30];

void solve()
{
	string s;
	cin >> s;

	memset(pre, 0, sizeof(pre));

	int cur_len = 0;
	for (auto &i : s)
	{
		if (pre[i - 'a'])
		{
			cur_len += 2;
			memset(pre, 0, sizeof(pre));
		}
		else pre[i - 'a'] = true;
	}

	cout << (int)s.length() - cur_len << '\n';
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