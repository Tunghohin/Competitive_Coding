#include <iostream>

using namespace std;

const int N = 500010;

int a[N];
struct Node
{
	int l, r;
	int t_max, l_max, r_max, sum;
}tr[4 * N];

void push_up(Node &root, Node &left, Node &right)
{
	root.sum = left.sum + right.sum;
	root.l_max = max(left.l_max, left.sum + right.l_max);
	root.r_max = max(right.r_max, right.sum + left.r_max);
	root.t_max = max(max(left.t_max, right.t_max), left.r_max + right.l_max);
}

void push_up(int u)
{
	push_up(tr[u], tr[u << 1], tr[u << 1 | 1]);
}

void build(int u, int l, int r)
{
	if (l == r) tr[u] = {l, r, a[l], a[l], a[l], a[l]};

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
	if (tr[u].l == x && tr[u].r == x) tr[u] = {x, x, v, v, v, v};

	else
	{
		int mid = (tr[u].l + tr[u].r) >> 1;

		if (x <= mid) modify(u << 1, x, v);
		else if (x > mid) modify(u << 1 | 1, x, v);

		push_up(u);
	}
}

Node query(int u, int l, int r)
{
	if (tr[u].l >= l && tr[u].r <= r) return tr[u];

	int mid = (tr[u].l + tr[u].r) >> 1;

	if (r <= mid) return query(u << 1, l, r);
	else if (l > mid) return query(u << 1 | 1, l, r);
	else
	{
		Node left = query(u << 1, l, r);
		Node right = query(u << 1 | 1, l, r);

		Node root;
		push_up(root, left, right);

		return root;
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

	int op, l, r;
	while (m--)
	{
		cin >> op >> l >> r;

		if (op == 1)
		{
			if (r < l) swap(l, r);

			cout << query(1, l, r).t_max << '\n';
		}

		else
		{
			modify(1, l, r);
		}
	}

	return 0;
}