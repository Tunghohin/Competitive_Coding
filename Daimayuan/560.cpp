#include <iostream>
#include <bitset>
#include <algorithm>
#include <cstring>

using namespace std;

typedef long long LL;

string sa, sb;
LL up, down;
int up_del[10], down_del[10];

bool is_sub(string a, string b)
{
	memset(down_del, 0, sizeof(down_del));
	int j = 0;
	for (int i = 0; i < (int)a.length(); i++)
	{
		if (a[i] == b[j]) j++;
		else
		{
			down_del[a[i] - '0']++;
		}
	}
	return j == (int)b.length();
}

bool check(LL new_down)
{
	string s = to_string(new_down);
	if (!is_sub(sb, s)) return false;
	for (int i = 1; i <= 9; i++) if (up_del[i] != down_del[i]) return false;
	if (up_del[0] == down_del[0]) return true;
	if (up_del[0] > down_del[0]) return false;

	string nsb = sb;
	int tot_zero = down_del[0] - up_del[0];
	for (int i = 0; i < (int)nsb.size(); i++)
	{
		if (nsb[i] == '0')
		{
			tot_zero--;
			if (tot_zero == 0)
			{
				nsb = nsb.substr(i + 1, nsb.length() - i);
				break;
			}
		}
	}

	return is_sub(nsb, s);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	LL a, b;
	cin >> a >> b;

	sa = to_string(a), sb = to_string(b);

	LL tmp = __gcd(a, b);
	up = a / tmp, down = b / tmp;

	LL res = a;

	for (int i = 1; i < (1 << (int)sa.length()); i++)
	{
		memset(up_del, 0, sizeof(up_del));
		string s;
		bitset<64> bs(i);
		for (int j = 0; j < (int)sa.length(); j++)
		{
			if (bs[j]) s.push_back(sa[j]);
			else up_del[sa[j] - '0']++;
		}

		LL new_up = stoll(s);
		if (new_up == 0) continue;
		if (new_up % up != 0) continue;
		if (check(new_up / up * down))
		{
			res = min(res, new_up);
		}
	}

	cout << res << ' ' << res / up * down << '\n';
}