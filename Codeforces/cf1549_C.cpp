#include <iostream>

using namespace std;

int Bigger[200010];

int main()
{
	int n, m;
	cin >> n >> m;

	int res = n;

	while (m--)
	{
		int f, t;
		cin >> f >> t;

		if (f > t)
		{
			Bigger[t]++;
			if (Bigger[t] == 1) res--;
		}
		else
		{
			Bigger[f]++;
			if (Bigger[f] == 1) res--;
		}
	}

	int q;
	cin >> q;

	while (q--)
	{
		int op;
		cin >> op;

		if (op == 3)
		{
			cout << res << '\n';
		}
		else if (op == 2)
		{
			int f, t;
			cin >> f >> t;
			if (f > t)
			{
				Bigger[t]--;
				if (Bigger[t] == 0) res++;
			}
			else
			{
				Bigger[f]--;
				if (Bigger[f] == 0) res++;
			}
		}
		else
		{
			int f, t;
			cin >> f >> t;

			if (f > t)
			{
				Bigger[t]++;
				if (Bigger[t] == 1) res--;
			}
			else
			{
				Bigger[f]++;
				if (Bigger[f] == 1) res--;
			}
		}
	}
}