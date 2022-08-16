#include <iostream>
#include <vector>

using namespace std;

bool check(const string &s)
{
	int op = 0;
	for (auto c : s)
	{
		if (c == '(') op++;
		if (c == ')') op--;
		if (op < 0) return false;
	}
	return op == 0;
}

void solve()
{
	string s;
	cin >> s;

	int op = s.size() / 2, cl = s.size() / 2;
	vector<int> pos;

	for (int i = 0; i < (int)s.length(); i++)
	{
		if (s[i] == '?') pos.push_back(i);
		if (s[i] == '(') op--;
		if (s[i] == ')') cl--;
	}

	for (int i = 0; i < (int)pos.size(); i++)
	{
		if (i < op) s[pos[i]] = '(';
		else s[pos[i]] = ')';
	}

	bool flag = true;
	if (op > 0 && cl > 0)
	{
		swap(s[pos[op - 1]], s[pos[op]]);
		if (check(s)) flag = false;
	}

	flag? cout << "Yes\n" : cout << "No\n";
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