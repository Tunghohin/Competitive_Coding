#include <iostream>

using namespace std;

const int N = 200010;

int a[N];
struct Node
{
	int l, r;
	int max;
}tr[4 * N];

void push_up(int u)
{
	tr[u].max = max(tr[u << 1].max, tr[u << 1 | 1].max);
}

void build(int u, int l, int r)
{
	if (l == r) tr[u] = {l, r, a[l]};

	else
	{
		tr[u] = {l, r};

		int mid = (l + r) >> 1;
		build(u << 1, l, mid);
		build(u << 1 | 1, mid + 1, r);

		push_up(u);
	}
}

void modify(int u, int x, int v)
{
	if (tr[u].l == x && tr[u].r == x) tr[u].max = v;

	else
	{
		int mid = (tr[u].l + tr[u].r) >> 1;

		if (x <= mid) modify(u << 1, x, v);
		else modify(u << 1 | 1, x, v);

		push_up(u);
	}
}

int query(int u, int l, int r)
{
	if (tr[u].l >= l && tr[u].r <= r) return tr[u].max;

	int mid = (tr[u].l + tr[u].r) >> 1;

	int res = 0;
	if (l <= mid) res = max(res, query(u << 1, l, r));
	if (r > mid) res = max(res, query(u << 1 | 1, l, r));

	return res;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int n, m;
	while (cin >> n >> m)
	{
		for (int i = 1; i <= n; i++) cin >> a[i];
		build(1, 1, n);

		char op;
		int l, r;
		while (m--)
		{
			cin >> op >> l >> r;

			if (op == 'U')
			{
				modify(1, l, r);
			}

			else
			{
				cout << query(1, l, r) << '\n';
			}
		}
	}

	return 0;
}