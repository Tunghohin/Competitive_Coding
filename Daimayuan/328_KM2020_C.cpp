#include <iostream>

using namespace std;

const int N = 5010;

int dp[N][N];
int arr[N], nxt[N];
int pos[N];

void solve()
{
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) pos[i] = n + 1;

	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
		if (i != 1 && arr[i] == arr[i - 1])
		{
			--n, --i;
		}
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = i; j <= n; j++) dp[i][j] = 0;
	}

	for (int i = n; i >= 1; i--)
	{
		nxt[i] = pos[arr[i]];
		pos[arr[i]] = i;
	}

	for (int length = 0; length < n; length++)
	{
		for (int l = 1; l + length <= n; l++)
		{
			int r = l + length;
			dp[l][r] = dp[l + 1][r];

			int x = nxt[l];
			while (x <= r)
			{
				dp[l][r] = max(dp[l][r], dp[l + 1][x - 1] + 1 + dp[x][r]);
				x = nxt[x];
			}
		}
	}

	cout << n - 1 - dp[1][n] << '\n';
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