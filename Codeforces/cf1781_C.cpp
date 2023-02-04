#include <bits/stdc++.h>

using namespace std;
using LL = long long;
using ULL = unsigned long long;
using PII = pair<int, int>;
using PLI = pair<long long, int>;
using PLL = pair<long long, long long>;

constexpr double PI = acos(-1);

struct node
{
	char c;
	int cnt;
};
vector<int> pos[26];

void solve()
{ 
	int n;
	string s;
	cin >> n >> s;

	for (int i = 0; i < 26; i++) pos[i].clear();

	map<char, int> mp;
	for (int i = 0; i < (int)s.length(); i++)
	{
		mp[s[i]]++;
		pos[s[i] - 'a'].push_back(i);
	}

	vector<node> v;
	for (int i = 0; i < 26; i++)
	{
		v.push_back({i + 'a', mp[i + 'a']});
	}

	auto comp = [=](node& a, node& b) {
		return a.cnt > b.cnt;
	};
	sort(v.begin(), v.end(), comp);

	// for (auto val : v)
	// {
	// 	cout << val.c << ' ' << val.cnt << '\n';
	// }

	string res_s;
	int res_val = -1;
	for (int k = 1; k <= min(n, 26); k++)
	{
		//cout << "k = " << k << '\n';
		if (n % k) continue;
		int cur_val = 0;
		for (int i = 0; i < k; i++)
		{
			cur_val += min(mp[v[i].c], n / k);
		}
		if (cur_val <= res_val) continue;

		//cout << cur_val << '\n';
		res_val = cur_val;

		vector<int> cur_pos[26];
		vector<int> free_idx;
		map<char, int> need_add;
		for (int i = 0; i < 26; i++) cur_pos[i] = pos[i];

		for (int i = 0; i < k; i++)
		{
			int cur_size = cur_pos[v[i].c - 'a'].size();
			if (cur_size < n / k)
			{
				need_add[v[i].c] += n / k - cur_size;
			}
			else if (cur_size > n / k)
			{
				while (cur_pos[v[i].c - 'a'].size() > n / k)
				{
					free_idx.push_back(cur_pos[v[i].c - 'a'].back());
					cur_pos[v[i].c - 'a'].pop_back();
				}
			}
		}
		for (int i = k; i < 26; i++)
		{
			while(!cur_pos[v[i].c - 'a'].empty())
			{
				free_idx.push_back(cur_pos[v[i].c - 'a'].back());
				cur_pos[v[i].c - 'a'].pop_back();
			}
		}

		for (int i = 0; i < k; i++)
		{
			while (need_add[v[i].c])
			{
				cur_pos[v[i].c - 'a'].push_back(free_idx.back());
				free_idx.pop_back();
				need_add[v[i].c]--;
			}
		}

		// for (auto val : v)
		// {
		// 	cout << val.c << ' ' << cur_pos[val.c - 'a'].size() << '\n';
		// }

		string tmp = s;
		for (int i = 0; i < 26; i++)
		{
			while (!cur_pos[v[i].c - 'a'].empty())
			{
				tmp[cur_pos[v[i].c - 'a'].back()] = v[i].c;
				cur_pos[v[i].c - 'a'].pop_back();
			}
		}

		res_s = tmp;
		//cout << tmp << '\n';
	}

	cout << n - res_val << '\n';
	cout << res_s << '\n';
}

signed main()
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