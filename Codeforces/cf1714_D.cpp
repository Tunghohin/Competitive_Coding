#include <iostream>
#include <vector>

using namespace std;
using PII = pair<int, int>;

int n;

vector<PII> res;
int get_nex(int pos, const string &s, const vector<string> &v)
{
	int matched = -1;
	PII cur_res = {-1, -1};

	for (int i = 0; i <= pos + 1; i++)
	{
		for (int j = 0; j < (int)v.size(); j++)
		{
			if (((i + (int)v[j].length() - 1) > matched) && ((int)(i + (int)v[j].length() - 1) > pos) && ((int)(i + (int)v[j].length() - 1) < s.length()) && (v[j] == s.substr(i, v[j].length())))
			{
				cur_res = {j + 1, i + 1};
				matched = max(matched, (int)(i + (int)v[j].length() - 1));
			}
		}
	}

	res.push_back(cur_res);
	return matched;
}

void solve()
{
	res.clear();

	string s;
	cin >> s;

	cin >> n;
	vector<string> v;
	for (int i = 1; i <= n; i++)
	{
		string x;
		cin >> x;
		v.push_back(x);
	}

	int now_pos = -1;
	while (true)
	{
		now_pos = get_nex(now_pos, s, v);
		if (now_pos == (int)s.length() - 1)
		{
			break;
		}
		if (now_pos == -1)
		{
			cout << -1 << '\n';
			return;
		}
	}

	cout << res.size() << '\n';
	for (auto u : res)
	{
		cout << u.first << ' ' << u.second << '\n';
	}
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