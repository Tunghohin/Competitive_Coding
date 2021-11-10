#include <iostream>
#include <vector>
#include <cstring>
#include <cmath>

using namespace std;

int arr[20];
int dif[20];
long long pos_10[20];

void solve()
{
	int n, k;
	cin >> n >> k;

	for (int i = 1; i <= n; i++) cin >> arr[i];

	for (int i = 1; i < n; i++)
	{
		dif[i] = (int)(pos_10[arr[i + 1]] / pos_10[arr[i]]);
		dif[i]--;
	}
	dif[n] = 0x3f3f3f3f;

	int pos = -1;
	int cnt = 0;
	for (int i = 1; i <= n; i++)
	{
		if (cnt + dif[i] <= k)
		{
			cnt += dif[i];
			pos = i;
		}
		else break;
	}

	if (pos == -1)
	{
		cout << (k + 1) * pos_10[arr[1]] << '\n';
		return;
	}

	long long res = 0;
	for (int i = 1; i <= pos; i++)
	{
		res += pos_10[arr[i]] * dif[i];
	}

	long long left = (k + 1) - cnt;
	res += left * (pos_10[arr[pos + 1]]);

	cout << res << '\n';
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int T;
	cin >> T;

	pos_10[0] = 1;
	for (int i = 1; i <= 10; i++) pos_10[i] = pos_10[i - 1] * 10ll;

	while (T--)
	{
		solve();
	}
}