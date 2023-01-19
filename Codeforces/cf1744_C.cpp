#include <bits/stdc++.h>

using namespace std;
using LL = long long;
using PII = pair<int, int>;

void solve()
{
	int n;
	char c;
	cin >> n >> c;

	string s;
	cin >> s;

	s = s + s; 

	if (c == 'g')
	{
		cout << 0 << '\n';
		return;
	}

	//cout << s << '\n';

	int res = 0;
	for (int i = 0, j = 0; i < s.length(); i++)
	{
		if (s[i] != c)
		{
			continue;
		}
		j = i;
		//if (s[i] == c) cout << '!';
		int cur_wait = 0;
		while (s[j] != 'g' && j < s.length())
		{
			cur_wait++;
			j++;
		}
		res = max(res, cur_wait);
		i = j;
	}

	cout << res << '\n';
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