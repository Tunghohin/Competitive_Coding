#include <iostream>

using namespace std;

const int N = 100010;
int mod;

int a[N];
struct Node
{
	int l, r;
	long long add, mul, sum;
}tr[4 * N];

inline void push_up(int u)
{
	tr[u].sum = (tr[u << 1].sum + tr[u << 1 | 1].sum) % mod;
}

inline void push_down(int u)
{
	Node &root = tr[u], &left = tr[u << 1], &right = tr[u << 1 | 1];

	left.sum = (left.sum * root.mul + (left.r - left.l + 1) * root.add) % mod;
	right.sum = (right.sum * root.mul + (right.r - right.l + 1) * root.add) % mod;

	left.mul = (left.mul * root.mul) % mod;
	right.mul = (right.mul * root.mul) % mod;

	left.add = (left.add * root.mul + root.add) % mod;
	right.add = (right.add * root.mul + root.add) % mod;

	root.add = 0;
	root.mul = 1;
}

void build(int u, int l, int r)
{
	if (l == r) tr[u] = {l, r, 0, 1, a[l] % mod};

	else
	{
		tr[u] = {l, r};
		tr[u].mul = 1;

		int mid = (l + r) >> 1;
		build(u << 1, l, mid);
		build(u << 1 | 1, mid + 1, r);

		push_up(u);
	}
}

void modify(int u, int l, int r, int v, bool op) //0 add, 1 mul
{
	if (tr[u].l >= l && tr[u].r <= r)
	{
		if (!op)
		{
			tr[u].add = (tr[u].add + v) % mod;
			tr[u].sum = (tr[u].sum + (tr[u].r - tr[u].l + 1) * v) % mod;
		}
		else
		{
			tr[u].add = (tr[u].add * v) % mod;
			tr[u].mul = (tr[u].mul * v) % mod;
			tr[u].sum = (tr[u].sum * v) % mod;
		}
	}

	else
	{
		push_down(u);

		int mid = (tr[u].l + tr[u].r) >> 1;

		if (l <= mid) modify(u << 1, l, r, v, op);
		if (r > mid) modify(u << 1 | 1, l, r, v, op);

		push_up(u);
	}
}

long long query(int u, int l, int r)
{
	if (tr[u].l >= l && tr[u].r <= r) return tr[u].sum;

	push_down(u);
	int mid = (tr[u].l + tr[u].r) >> 1;
	long long sum = 0;

	if (l <= mid) sum = query(u << 1, l, r) % mod;
	if (r > mid) sum = (sum + query(u << 1 | 1, l, r)) % mod;

	return sum;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int n, m;
	cin >> n >> m >> mod;

	for (int i = 1; i <= n; i++) cin >> a[i];

	build(1, 1, n);

	int op, l, r, k;
	while (m--)
	{
		cin >> op >> l >> r;

		if (op == 1)
		{
			cin >> k;
			modify(1, l, r, k, true);
		}

		else if (op == 2)
		{
			cin >> k;
			modify(1, l, r, k, false);
		}

		else
		{
			cout << query(1, l, r) << '\n';
		}
	}

	return 0;
}