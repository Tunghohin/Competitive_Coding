#include <iostream>
#include <vector>

using namespace std;

typedef long long LL;

const LL Pow2Lim = 2e18;

vector<string> P2;

int check(const string &p, const string &s)
{
	int sp = 0;
	int pp = 0;
	int cnt = 0;

	while (pp < p.length() && sp < s.length())
	{
		if (p[pp] == s[sp])
		{
			cnt++;
			pp++;
		}
		sp++;
	}

	return (int)s.length() - cnt + (int)p.length() - cnt;
}

int main()
{
	for (LL Pow2 = 1; Pow2 <= Pow2Lim; Pow2 *= 2)
	{
		P2.push_back(to_string(Pow2));
	}

	int T;
	cin >> T;

	while (T--)
	{
		string s;
		cin >> s;

		int ans = 2 * (int)s.length();

		for (const auto &i : P2)
		{
			ans = min(ans, check(i, s));
		}

		cout << ans << '\n';
	}
}