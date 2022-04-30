#include <iostream>

using namespace std;

const int N = 200010;

int f[N];
long long w[N];

int find(int x)
{
	if (f[x] == x) return x;
	int p = f[x];
	find(p);
	w[x] += w[p];
	return f[x] = f[p];
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int n, q;
	cin >> n >> q;

	for (int i = 1; i <= n; i++)
	{
		f[i] = i;
		w[i] = 0;
	}

	long long t = 0;
	for (int i = 1; i <= q; i++)
	{
		int op, l, r;
		cin >> op >> l >> r;
		l = (l + t) % n + 1;
		r = (r + t) % n + 1;

		if (op == 2)
		{
			if (find(l) != find(r)) continue;
			else cout << w[l] - w[r] << '\n';
			t = abs(w[l] - w[r]);
		}
		else
		{
			int x;
			cin >> x;

			if (find(l) == find(r)) continue;
			w[f[l]] = x - w[l] + w[r];
			f[f[l]] = f[r];
		}
	}
}