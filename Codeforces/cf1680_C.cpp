#include <iostream>

using namespace std;

string s;
int pos[200010];
int cnt;

bool check(int mid)
{
	if (mid >= cnt) return true;
	int left = cnt - mid;

	for (int i = 1; i <= mid + 1; i++)
	{
		int l = pos[i];
		int r;
		if (i + left - 1 <= cnt)
		{
			r = pos[i + left - 1];
		} else r = cnt;

		if (r - l + 1 - left <= mid) return true;
	}
	return false;
}

void solve()
{
	cin >> s;

	cnt = 0;
	for (int i = 0; i <= (int)s.length(); i++) pos[i] = 0;

	for (int i = 0; i < (int)s.length(); i++)
	{
		if (s[i] == '1')
		{
			pos[++cnt] = i;
		}
	}

	int l = 0, r = 200010;
	while (l < r)
	{
		int mid = (l + r) >> 1;
		if (check(mid)) r = mid;
		else l = mid + 1;
	}

	cout << l << '\n';
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