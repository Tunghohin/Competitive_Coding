#include <bits/stdc++.h>

using namespace std;
using LL = long long;
using ULL = unsigned long long;
using PII = pair<int, int>;
using PLI = pair<long long, int>;
using PLL = pair<long long, long long>;

int a[100010];
LL C[100010][5];

void solve()
{
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) cin >> a[i];

	sort(a + 1, a + 1 + n);
	
	if (a[1] <= a[2] && a[2] < a[3])
	{
		int cnt = 1;
		for (int i = 4; i <= n; i++)
		{
			if (a[i] == a[i - 1]) cnt++;
			else break;
		}
		cout << cnt << '\n';
	}
	else if (a[1] < a[2] && a[2] == a[3])
	{
		int cnt = 2;
		for (int i = 4; i <= n; i++)
		{
			if (a[i] == a[i - 1]) cnt++;
			else break;
		}
		cout << C[cnt][2];
	}
	else if(a[1] == a[2] && a[2] == a[3])
	{
		int cnt = 3;
		for (int i = 4; i <= n; i++)
		{
			if (a[i] == a[i - 1]) cnt++;
			else break;
		}
		cout << C[cnt][3] << '\n';
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int T;
	T = 1;

	for (int i = 0; i <= 100000; i++)
	{
		for (int j = 0; j <= 3 && j <= i; j++)
		{
			if (j == 0) C[i][j] = 1;
			else C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
		}
	}

	while (T--)
	{
		solve();
	}
}