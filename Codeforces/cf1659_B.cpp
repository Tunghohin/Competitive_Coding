#include <iostream>

using namespace std;

int cnt[200010];
void solve()
{
	int n, k;
	cin >> n >> k;
	string s;
	cin >> s;

	for (int i = 0; i < s.length(); i++) cnt[i] = 0;

	string res;
	int cur_k = k;
	for (int i = 0; i < s.length() - 1 && cur_k; i++)
	{
		if ((k % 2) == 1)
		{
			if (s[i] == '1' && cur_k)
			{
				cur_k--;
				cnt[i]++;
				if (!cur_k) break;
			}
		}
		else
		{
			if (s[i] == '0' && cur_k)
			{
				cur_k--;
				cnt[i]++;
				if (!cur_k) break;
			}
		}
	}

	if (cur_k) cnt[s.length() - 1] = cur_k;
	for (int i = 0; i < s.length(); i++)
	{
		if ((k - cnt[i]) % 2 == 1)
		{
			s[i] == '0'? res.push_back('1') : res.push_back('0');
		}
		else
		{
			s[i] == '0'? res.push_back('0') : res.push_back('1');
		}
	}

	cout << res << '\n';
	for (int i = 0; i < s.length(); i++) cout << cnt[i] << ' ';
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