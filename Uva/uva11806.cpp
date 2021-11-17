#include <iostream>

using namespace std;

int C[510][510];

const int mod = 1000007;

void solve(int case_cnt)
{
	long long res = 0;

	int n, m, k;
	cin >> n >> m >> k;
	for (int set = 0; set < 16; set++)
	{
		int r = n, c = m, cnt = 0;
		if (set & 1) {r--, cnt++;}
		if (set & 2) {r--, cnt++;}
		if (set & 4) {c--, cnt++;}
		if (set & 8) {c--, cnt++;}

		if (cnt & 1) res = (res + mod - C[r * c][k]) % mod;
		else res = (res + C[r * c][k]) % mod;
	}

	cout << "Case " << case_cnt << ": " << res << '\n';
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int T;
	cin >> T;

	C[0][0] = 1;
	for (int i = 0; i <= 500; i++)
	{
		C[i][0] = C[i][i] = 1;
		for (int j = 1; j < i; j++)
		{
			C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % mod;
		}
	}

	for (int i = 1; i <= T; i++)
	{
		solve(i);
	}
}