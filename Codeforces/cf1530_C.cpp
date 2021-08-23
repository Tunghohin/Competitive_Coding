#include <iostream>
#include <algorithm>

using namespace std;

bool cmp(int a, int b)
{
	return a > b;
}

int a[200010];
int b[200010];
int s_a[200010];
int s_b[200010];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int T;
	cin >> T;

	while (T--)
	{
		int n;
		cin >> n;

		for (int i = 1; i <= n; i++) cin >> a[i];
		for (int i = 1; i <= n; i++) cin >> b[i];

		sort(a + 1, a + 1 + n);
		sort(b + 1, b + 1 + n);

		for (int i = 1; i <= n; i++)
		{
			s_a[i] = s_a[i - 1] + a[i];
			s_b[i] = s_b[i - 1] + b[i];
		}

		int sc_a = 0, sc_b = 0;
		int res = 0;
		for (res = 0;;res++)
		{
			sc_a = s_a[n] - s_a[(n + res)/4] + res * 100;
			sc_b = s_b[n] - s_b[max(0, (n + res) / 4 - res)];

			if (sc_a >= sc_b) break;
		}

		cout << res << '\n';
	}
}