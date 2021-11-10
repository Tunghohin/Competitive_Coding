#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cmath>

using namespace std;

void solve()
{
	int n;
	string s;
	cin >> n >> s;

	int cnt = 0;
	for (int i = 0; i < n; i++) cnt += (s[i] == '*'? 1 : 0);

	if (cnt == 1 || cnt == 0)
	{
		cout << 0 << '\n';
		return;
	}

	int pos = -1;
	int now = -1;

	for (int i = 0; i < n; i++)
	{
		if (s[i] == '*')
		{
			now++;
			if (now == cnt / 2)
			{
				pos = i;
				break;
			}
		}
	}

	long long res = 0;
	int left_cnt = 0;
	for (int i = pos - 1; i >= 0; i--)
	{
		if (s[i] == '*')
		{
			res += pos - i - 1 - left_cnt;
			left_cnt++;
		}
	}

	int right_cnt = 0;
	for (int i = pos + 1; i < n; i++)
	{
		if (s[i] == '*')
		{
			res += i - pos - 1 - right_cnt;
			right_cnt++;
		}
	}

	cout << res << '\n';
}

int main()
{
	int T;
	scanf("%d", &T);

	while (T--)
	{
		solve();
	}
}