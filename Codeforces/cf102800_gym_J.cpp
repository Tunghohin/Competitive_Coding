#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <unordered_map>

using namespace std;
using LL = long long;

unordered_map<string, int> a_mp, b_mp;

int calc_pt(string &s)
{
	int a_pt = 0;
	int b_pt = 0;

	for (int i = 0; i < 3; i++)
	{
		if (s[i] == s[i + 3] && s[i + 3] == s[i + 6])
		{
			if (s[i] == '1') a_pt++;
			else b_pt++;
		}
	}
	for (int i = 0; i < 9; i += 3)
	{
		if (s[i] == s[i + 1] && s[i + 1] == s[i + 2])
		{
			if (s[i] == '1') a_pt++;
			else b_pt++;
		}
	}
	if (s[0] == s[4] && s[4] == s[8])
	{
		if (s[0] == '1') a_pt++;
		else b_pt++;
	}
	if (s[2] == s[4] && s[4] == s[6])
	{
		if (s[2] == '1') a_pt++;
		else b_pt++;
	}
	return a_pt - b_pt;
}

int cnt = 0;
int dfs(string st, int rd)
{
	// cnt++;
	// if (cnt >= 12) return 0;
	// cout << rd << "!\n";
	// cout << st << '\n';

	if (rd == 0 && b_mp.count(st)) return b_mp[st];
	if (rd == 1 && a_mp.count(st)) return a_mp[st];

	int mn_res = 0x3f3f3f3f, mx_res = -0x3f3f3f3f;
	for (int i = 0; i < 9; i++)
	{
		//if (cnt >= 12) return 0;
		if (st[i] != '0') continue;
		string tmp = st;

		if (rd == 0)
		{	
			tmp[i] = '2';
			mn_res = min(mn_res, dfs(tmp, 1));
		}
		else
		{
			tmp[i] = '1';
			mx_res = max(mx_res, dfs(tmp, 0));
		}
	}

	if (rd == 0) return b_mp[st] = mn_res;
	else return a_mp[st] = mx_res;
}

void solve()
{
	int fst;
	cin >> fst;

	string op;
	for (int i = 0; i < 3; i++)
	{
		string tmp;
		cin >> tmp;
		for (auto c : tmp)
		{
			if (c == '.') op.push_back('0');
			else if (c == 'O') op.push_back('1');
			else op.push_back('2');
		}
	}

	dfs(op, fst);

	if (fst == 0) cout << b_mp[op];
	else cout << a_mp[op];
	cout << '\n';
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	for (int i = 0; i < (1 << 9); i++)
	{
		string tmp;
		for (int k = 0; k < 9; k++)
		{
			if ((i >> k) & 1)
			{
				tmp.push_back('1');
			} else tmp.push_back('2');
		}
		int pt = calc_pt(tmp);
		//cout << pt << '\n';
		a_mp[tmp] = pt;
		b_mp[tmp] = pt;
	}

	int T;
	cin >> T;

	while (T--)
	{
		solve();
	}
}