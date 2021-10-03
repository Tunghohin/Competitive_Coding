#include <iostream>

using namespace std;

const int N = 100010;

int a[N];
struct Node
{
	int l, r;
	long long add, sum;
}tr[4 * N];

void push_up(int u)
{
	tr[u].sum = tr[u << 1].sum + tr[u << 1 | 1].sum;
}

void push_down(int u)
{
	Node &root = tr[u], &left = tr[u << 1], &right = tr[u << 1 | 1];

	if (root.add)
	{
		left.add += root.add, left.sum += (long long)(left.r - left.l + 1) * root.add;
		right.add += root.add, right.sum += (long long)(right.r - right.l + 1) * root.add;
		root.add = 0;
	}
}

void build(int u, int l, int r)
{
	if (l == r) tr[u] = {l, r, 0, a[l]};

	else
	{
		tr[u] = {l, r};

		int mid = (l + r) >> 1;
		build(u << 1, l, mid);
		build(u << 1 | 1, mid + 1, r);

		push_up(u);
	}
}

void modify(int u, int l, int r, int v)
{
	if (tr[u].l >= l && tr[u].r <= r)
	{
		tr[u].add += v;
		tr[u].sum += (long long)(tr[u].r - tr[u].l + 1) * v;
	}

	else
	{
		push_down(u);

		int mid = (tr[u].l + tr[u].r) >> 1;
		if (l <= mid) modify(u << 1, l, r, v);
		if (r > mid) modify(u << 1 | 1, l, r, v);

		push_up(u);
	}
}

long long query(int u, int l, int r)
{
	if (tr[u].l >= l && tr[u].r <= r) return tr[u].sum;

	push_down(u);
	int mid = (tr[u].l + tr[u].r) >> 1;
	long long sum = 0;

	if (l <= mid) sum = query(u << 1, l, r);
	if (r > mid) sum += query(u << 1 | 1, l, r);

	return sum;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= n; i++) cin >> a[i];
	build(1, 1, n);

	int op, l, r, k;
	while (m--)
	{
		cin >> op >> l >> r;

		if (op == 1)
		{
			cin >> k;
			modify(1, l, r, k);
		}

		else
		{
			cout << query(1, l, r) << '\n';
		}
	}

	return 0;
}