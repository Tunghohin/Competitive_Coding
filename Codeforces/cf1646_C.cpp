#include <iostream>
#include <algorithm>

using namespace std;

long long count_one(long long x)
{
	int cnt = 0;
	for (int k = 62; k >= 0; k--)
	{
		if ((x >> k & 1)) cnt++;
	}
	return cnt;
}

long long get_fact(long long x)
{
	long long res = 1;
	while (x)
	{
		res *= x;
		x--;
	}
	return res;
}

long long fact_set[15];
void solve()
{
	long long n;
	cin >> n;

	long long res = 0x3f3f3f3f;
	for (long long i = 0; i <= (1 << 14) - 1; i++)
	{
		long long cnt = 0;
		long long sum = 0;
		for (int k = 13; k >= 0; k--)
		{
			if ((i >> k) & 1)
			{
				cnt++;
				sum += fact_set[k];
			}
		}

		if (sum > n) continue;
		long long need = n - sum;
		res = min(res, cnt + count_one(need));
	}

	cout << res << '\n';
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int T;
	cin >> T;

	for (int i = 1; i <= 14; i++)
	{
		fact_set[i - 1] = get_fact((long long)i);
	}

	while (T--)
	{
		solve();
	}
}