#include <iostream>

using namespace std;

const int N = 200010;

int a[N];

struct Node
{
	int l, r;
	int maxv;
}tr[4 * N];

void push_up(int u)
{
	tr[u].maxv = max(tr[u << 1].maxv, tr[u << 1 | 1].maxv);
}

void build(int u, int l, int r)
{
	if (l == r)
	{
		tr[u].l = tr[u].r = l;
		tr[u].maxv = a[l];
		return;
	}

	tr[u].l = l, tr[u].r = r;
	int mid = (l + r) >> 1;
	build(u << 1, l, mid);
	build(u << 1 | 1, mid + 1, r);

	push_up(u);
}

void modify(int u, int x, int v)
{
	if (tr[u].l == x && tr[u].r == x)
	{
		tr[u].maxv = v;
		return;
	}

	int mid = (tr[u].l + tr[u].r) >> 1;
	if (x <= mid) modify(u << 1, x, v);
	else modify(u << 1 | 1, x, v);

	push_up(u);
}

int query(int u, int l, int r, int v)
{
	if (tr[u].l == tr[u].r)
	{
		return tr[u].l;
	}

	int mid = (tr[u].l + tr[u].r) >> 1;
	if (r <= mid) return query(u << 1, l, r, v);
	else if (l > mid) return query(u << 1 | 1, l, r, v);
	else
	{
		int pos = query(u << 1, l, mid, v);
		if (pos == -1) query(u << 1 | 1, mid + 1, r, v);
		else return pos;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= n; i++) cin >> a[i];

	build(1, 1, n);

	while (m--)
	{
		int op;
		cin >> op;
		if (op == 1)
		{
			int x, v;
			cin >> x >> v;
			modify(1, x, v);
		}

		else
		{
			int l, r, d;
			cin >> l >> r >> d;
			int res = query(1, l, r, d);
			if (res <= r) cout << res << '\n';
			else cout << -1 << '\n';
		}
	}
}