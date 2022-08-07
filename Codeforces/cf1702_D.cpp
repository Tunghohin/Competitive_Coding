#include <iostream>
#include <cstring>

using namespace std;

int latter_cnt[30];

void solve()
{
	int p;
	string s;
	cin >> s >> p;

	memset(latter_cnt, 0, sizeof(latter_cnt));

	long long cur_val = 0;
	for (auto c : s)
	{
		latter_cnt[c - 'a' + 1]++;
		cur_val += c - 'a' + 1;
	}

	for (int i = 26; i >= 1; i--)
	{
		while (latter_cnt[i] && cur_val > p)
		{
			cur_val -= i;
			latter_cnt[i]--;
		}
	}

	for (auto c : s)
	{
		if (latter_cnt[c - 'a' + 1])
		{
			cout << c;
			latter_cnt[c - 'a' + 1]--;
		}
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