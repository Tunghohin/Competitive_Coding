#include <iostream>

using namespace std;

int c[1000010];
int r[1000010];

void init(int n, int m)
{
	for (int i = 0; i <= max(n, m); i++)
	{
		c[i] = r[i] = 0;
	}
}

void solve()
{
	int n, m;
	cin >> n >> m;
	string s;
	cin >> s;
	int last = -0x3f3f3f3f;

	init(n, m);
	int c_cnt = 0;

	for (int i = 0; i < n * m; i++)
	{
		char ch = s[i];
		if (ch == '1')
		{
			last = i;
			if (c[i % m] == 0)
			{
				c_cnt++;
				c[i % m] = 1;
			}
		}
		if (i - last < m)
		{
			r[i % m]++;
		}
		if (i != 0) cout << ' ';
		cout << r[i % m] + c_cnt;
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