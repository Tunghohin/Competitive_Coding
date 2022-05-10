#include <iostream>

using namespace std;

int a[200010];
int od_a1[200010];
int od_a2[200010];

void solve()
{
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) cin >> a[i];

	bool flag = true;

	if (n % 2)
	{
		bool flag1 = true, flag2 = true;
		for (int i = 1; i <= n; i++)
		{
			od_a1[i] = od_a2[i] = a[i];
		}

		for (int i = 1; i <= n; i += 2)
		{
			if (i + 1 <= n && od_a1[i] > od_a1[i + 1])
			{
				swap(od_a1[i], od_a1[i + 1]);
			}
		}

		for (int i = 2; i <= n; i += 2)
		{
			if (od_a2[i] > od_a2[i + 1])
			{
				swap(od_a2[i], od_a2[i + 1]);
			}
		}

		for (int i = 1; i < n; i++)
		{
			if (od_a1[i] > od_a1[i + 1]) flag1 = false;
			if (od_a2[i] > od_a2[i + 1]) flag2 = false;
		}

		flag = flag2;

	}
	else
	{
		for (int i = 1; i <= n; i += 2)
		{
			if (a[i] > a[i + 1])
			{
				swap(a[i], a[i + 1]);
			}
		}

		for (int i = 1; i < n; i++)
		{
			if (a[i] > a[i + 1])
			{
				flag = false;
				break;
			}
		}
	}

	flag? cout << "YES\n" : cout << "NO\n";
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